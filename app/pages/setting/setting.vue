<template>

  <view class="container">
	
	<threshold
		target= '温度'
		v-model="thresholds.temperature"
	/>
	
    <threshold
    	target= '湿度'
    	v-model="thresholds.humidity"
    />
	
	<threshold
		target= '烟雾'
		v-model="thresholds.gas"
	/>

    <button class="submit-btn" @click="saveSettings">保存设置</button>
  </view>
</template>

<script>
import threshold from '@/components/threshold.vue'
import mqtt from '@/common/mqttService.js'
const db = uniCloud.database()

export default {
	components:{
		threshold
	},
	data() {
		return {
			thresholds: {
				temperature: 0, 
				humidity: 0,
				gas: 0
			}
		}
	},
	onLoad() {
		this.getData()
	},
	methods: {
		getData(){
			const device = uni.getStorageSync('device')
			for (const key in this.thresholds) {
				const index = device.sensorList.findIndex(item => item.id === key)
				this.thresholds[key] = device.sensorList[index].threshold
			}
		},
		async saveSettings() {
			console.log(this.thresholds.temperature,this.thresholds.humidity,this.thresholds.gas)
			
			const device = uni.getStorageSync('device')
			for (const [key, threshold] of Object.entries(this.thresholds)) {
				const index = device.sensorList.findIndex(item => item.id === key)
				
				if (index !== -1) {
					this.$set(device.sensorList, index, {
						...device.sensorList[index],
						threshold
					})
				}
			}
			
			const target = {
				"version": "1.0.0",
				"method": "thing.event.property.post",
				"id": "654321",
				"params": {},
				timestamp: Date.now()
			}
			
			for (const [key, value] of Object.entries(this.thresholds)) {
				target.params[`${key}_threshold`] = value
			}
			mqtt.publish(target)
			console.log(target)
			
			// 2. 更新 devices 表实时数据
			await db.collection('devices').doc(device.id).update({
				sensorList: device.sensorList,
				lastActive: Date.now()
			})
			
			uni.showToast({
				title: '设置保存成功',
				icon: 'success'
			})
		}
	}
}
</script>

<style scoped>
	.container {
	  padding: 40rpx;
	}
	.form-item {
	  margin-bottom: 60rpx;
	}
	.label {
	  display: block;
	  margin-bottom: 20rpx;
	  font-size: 32rpx;
	  color: #333;
	}
	.input {
	  border: 1rpx solid #eee;
	  padding: 20rpx;
	  border-radius: 16rpx;
	  font-size: 32rpx;
	}
	.submit-btn {
	  background: #007AFF;
	  color: white;
	  margin-top: 80rpx;
	}
</style>