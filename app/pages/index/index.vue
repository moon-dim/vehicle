<template>
	<view class="container">
		<view class="head">
			<image src="/static/images/logo.png"></image>
			<view>{{title}}</view>
		</view>
		
		<device 
			:name="device.name"
			:isOnline="device.online"
			:lastActive="device.lastActive"
		/>
		
		<!-- 位置天气信息 -->
		<weather />
		
		<!-- 视频播放组件 -->
		<player ref="muiplayer" :src="videosrc"/>
		
		<!-- 设备状态列表组件 -->
		<sensor 
			:sensorList="device.sensorList" 
			@sensor-change="sensorChange"
			@sensor-box-click="showHistoryChart"
		/>
		
		 <!-- 图表弹窗 -->
		<uni-popup ref="chartPopup" type="center" @change="popupChange">
			<view class="chart-container">
				<qiun-data-charts
				  type="line"
				  :chartData="chart.data"
				  :opts="chart.opts"
				/>
			</view>
		</uni-popup>
	</view>
</template>

<script>
import device from '@/components/device.vue'
import player from '@/components/player.vue'
import sensor from '@/components/sensor.vue'
import weather from '@/components/weather.vue'
import mqtt from '@/common/mqttService.js'

const db = uniCloud.database()
const deviceId = "683582667ad52db7e7a4d368"

export default {
	components:{
		device,
		player,
		sensor,
		weather
	},
	data() {
		return{
			title: '车内滞留儿童监测及应急处置系统',
			videosrc: 'http://47.93.33.13:80/live?port=1935&app=live&stream=stream',
			device: {
				name: '',
				id: '',
				sensorList: [],
				lastActive: 0,
				online: false
			},
			chart: {
				isShow: false,
				activate: '',
				data: {},
				opts: {
					update:true,
					enableScroll: true,
					scrollPosition: 'right',
					animation: false,
					duration: 0,
					yAxis: {
						disabled: true,
						disableGrid: true
					},
					xAxis: {
						itemCount: 5
					}
				}
			}
		}
	},
	onLoad() {
		this.getSensorData()
		mqtt.connect()
		mqtt.handleMessage(this, this.messageHandler)
	},
	onUnload() {
	    mqtt.disconnect()
	},
	methods: {
		async getSensorData(){
			const res = await db.collection('devices').doc(deviceId).get()
			const dbData = res.result.data[0]
			console.log(dbData)
			
			this.device = {
			  name: dbData.deviceName || '',
			  id: deviceId,
			  sensorList: dbData.sensorList ? [...dbData.sensorList] : [],
			  lastActive: dbData.lastActive ? dbData.lastActive : 0,
			  online: !!dbData.online
			}
			uni.setStorageSync('device', this.device)
			console.log("传感器数据读取成功")
		},
		sensorChange(payload) {
			// 找到对应传感器
			const index = this.device.sensorList.findIndex(item => item.id === payload.id)
			
			// 响应式更新
			this.$set(this.device.sensorList, index, payload)
			uni.setStorageSync('device', this.device)
			
			const target = {
				"version": "1.0.0",
				"method": "thing.event.property.post",
				"id": "654321",
				"params": {},
				timestamp: new Date().toISOString()
			}
			
			this.device.sensorList.forEach(item => {
				// 仅处理包含 id 和 value 的有效项
				if (item.id !== undefined && item.value !== undefined && !item.onlyShow) {
					target.params[item.id] = item.value;
				}
			});
			console.log(target)
			mqtt.publish(target)
		},
		async showHistoryChart(sensorId) {
			this.chart.activate = sensorId
			this.getChartDataFromDB(sensorId)
		    this.$refs.chartPopup.open()
		},
		async messageHandler(topic, receiveData){
			console.log('MQTT消息 [主题]:', topic, '[内容]:', receiveData)
			const date = Date.now();
			if(!receiveData?.params)return
			if(receiveData.params.deviceId){
				if(receiveData.params.deviceId===deviceId){
					this.$set(this.device, 'online', true)
					this.$set(this.device, 'lastActive', date)
					console.log("设备已连接！",this.device.online)
				}
				else {
					console.log("设备连接错误！")
				}
				return
			}
			
			
			Object.entries(receiveData.params).forEach(([sensorId, value]) => {
				const index = this.device.sensorList.findIndex(item => item.id === sensorId)
				// console.log("sensorId:",sensorId,"value:",value,"index:",index)
				
				if (index !== -1) {
					// 前端响应式更新
					this.$set(this.device.sensorList, index, {
						...this.device.sensorList[index],
						value
					});
					if(this.chart.activate === sensorId){
						this.chart.data.categories.push(this.getTime(date));
						this.chart.data.series[0].data.push(value);
						if (this.chart.data.categories.length > 5) {
							this.chart.data.categories.shift();
							this.chart.data.series[0].data.shift();
						}
						
					}
				}
			})
			uni.setStorageSync('device', this.device)
			
			
			// 2. 更新 devices 表实时数据
			await db.collection('devices').doc(deviceId).update({
				sensorList: this.device.sensorList,
				lastActive: date
			})

			
			// 3. 插入传感器历史记录
			const historyList = Object.entries(receiveData.params).map(([sensorId, value]) => ({
			    deviceId,
			    sensorId,
			    value,
			    timestamp: date
			}))
			
			await db.collection('sensor_history').add(historyList)
			
		},
		async getChartDataFromDB(sensorId) {
			this.chart.data = {}
			const index = this.device.sensorList.findIndex(item => item.id === sensorId)
			const query = {deviceId, sensorId}
			// console.log(query)
			const dbres =  await db.collection('sensor_history')
				.where(query)
				.field({
					timestamp: true,
					value: true,
					// _id: false
				})
				.orderBy('timestamp','desc')
				.limit(5)
				.get()

			const sortedList = [...dbres.result.data].sort((a, b) => a.timestamp - b.timestamp)
			const categories = sortedList.map(item => this.getTime(item.timestamp))
			const values = sortedList.map(item => item.value)
			console.log(categories,values)
			let res = {
				categories,
				series: [
					{
						name: this.device.sensorList[index].name,
						data: values
					}
				],
				animation: false
			};
			this.chart.data = JSON.parse(JSON.stringify(res));
		},
		popupChange(){
			this.chart.isShow = !this.chart.isShow;
			if(!this.chart.isShow) this.chart.activate = '';
			console.log('isshow: ',this.chart.isShow,"activate: ",this.chart.activate);
		},
		getTime(dateString) {
			if (!dateString) return '-'
			const date = new Date(dateString)
			const year = date.getFullYear()
			const month = String(date.getMonth() + 1).padStart(2, '0')
			const day = String(date.getDate()).padStart(2, '0')
			const hour = String(date.getHours()).padStart(2, '0')
			const minute = String(date.getMinutes()).padStart(2, '0')
			const second = String(date.getSeconds()).padStart(2, '0')
			return `${hour}:${minute}:${second}`
		}
	}
}
</script>

<style>
	.head {
	  display: flex;
	  padding-top: 120rpx;
	}
	
	.head>image {
	  width: 100rpx;
	  height: 100rpx;
	  margin-left: 20rpx;
	}
	
	.head>view {
	  margin-left: 10rpx;
	  font-size: 40rpx;
	  font-weight: 600;
	  line-height: 100rpx;
	}
	
	.status-panel {
	  background: #fff;
	  border-radius: 16rpx;
	  margin: 30rpx;
	  padding: 20rpx;
	  box-shadow: 0 4rpx 12rpx rgba(0,0,0,0.1);
	}
	
	.panel-title {
	  font-size: 32rpx;
	  font-weight: bold;
	  color: #333;
	  padding-bottom: 20rpx;
	  border-bottom: 1rpx solid #eee;
	}
	
	.device-item {
	  display: flex;
	  align-items: center;
	  padding: 25rpx 0;
	  border-bottom: 1rpx solid #f5f5f5;
	}
	
	.status-icon {
	  width: 40rpx;
	  height: 40rpx;
	  margin-right: 20rpx;
	}
	
	.device-name {
	  flex: 1;
	  font-size: 28rpx;
	  color: #666;
	}
	
	.status-text {
	  width: 100rpx;
	  height: 30px;
	  line-height: 10px;
	  text-align: center;
	  font-size: 26rpx;
	
	}
	
	.online {
	  background: #e8f5e9;
	  color: #4caf50;
	}
	
	.offline {
	  background: #ffebee;
	  color: #f44336;
	}
	
	.last-active {
	  font-size: 24rpx;
	  color: #999;
	  margin-left: 30rpx;
	}
	
	.chart-container {
	  width: 100%;
	  height: 600rpx;
	  background: white;
	  border-radius: 20rpx;
	  padding: 20rpx;
	}
</style>
