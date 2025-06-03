<template>
	<view class="sensors-system">
	  <view 
			v-for="(item,index) in sensorList"
			:key="index"
			@click="item.onlyShow?$emit('sensor-box-click', item.id):null"
			class="system-info">
	    <view style="display: flex;margin-top:15rpx ;align-items: center;width: 150rpx;justify-content: center;">
			<image :src="item.imageUrl" mode="widthFix" style="width: 80rpx;"></image>
	    </view>
	    <view v-if="item.onlyShow">
			<view 
				class="sensors-system-box2"
				style="width: 100%; height: 100%;"
			>
				<view><span style="font-size: 18px; font-weight: 600;">{{item.value}}</span> {{item.unit}} </view>
				<view> {{item.name}} </view>
				<!-- <view>{{item.top}}-{{item.bottom}}</view> -->
			</view>
	    </view>
	    <view v-else>
	      <view class="sensors-system-box2">
	        <view></view>
	        <switch :checked="item.value" :data-param="index" color="#97baff" @change="buttonChange"></switch>
	        <view>{{item.name}}</view>
	      </view>
	    </view>
	  </view>
	</view>
</template>

<script>
	export default {
		name:"sensor",
		props: {
			sensorList: {
				type: Array,
				default: () => [],
				validator: (value) => {
					return value.every(item => {
						return (
							typeof item.name === 'string' &&
							typeof item.id === 'string' &&
							typeof item.imageUrl === 'string' &&
							(typeof item.value === 'number' || typeof item.value === 'boolean' || typeof item.value === 'string') &&
							(item.unit === undefined || typeof item.unit === 'string') &&
							typeof item.onlyShow === 'boolean'
						)
					})
				}
			}
		},
		data() {
			return {
				localSensorList: JSON.parse(JSON.stringify(this.sensorList))
			};
		},
		methods: {
			buttonChange(e) {
				const index = e.currentTarget.dataset.param
				const updatedItem = {
				      ...this.localSensorList[index],
				      value: !this.localSensorList[index].value
				    }
				//  更新本地副本
				this.$set(this.localSensorList, index, updatedItem)
				
				// 触发自定义事件（关键步骤）
				this.$emit('sensor-change', {
				  id: updatedItem.id,
				  value: updatedItem.value
				})
			},
			handleBoxClick(sensorId) {
			    this.$emit('sensor-box-click', sensorId)
			}
		}
	}
</script>

<style scoped>
	.sensors-system {
	  display: flex;
	  width: 95%;
	  flex-wrap: wrap;
	  margin: 0 0 0 34rpx;
	}
	
	.system-info {
	  display: flex;
	  width: calc(50% - 23rpx);
	  height: 205rpx;
	  box-shadow: 0 8rpx 20rpx 0 rgba(0, 0, 0, 0.3);
	  background-color: #ffffff;
	  border-radius: 32rpx;
	  margin: 0 23rpx 23rpx 0;
	}
	
	@media screen and (max-width: 320px) {
	  .system-info {
	    width: 100%; /* 小屏幕单列显示 */
		height: 305rpx;
		margin: 0 23rpx 23rpx 0;
	  }
	}
	
	.sensors-system-box2 {
	  flex: 1;
	  margin-top: 19rpx;
	  width: 190rpx;
	  cursor: pointer;
	  transition: all 0.2s;
	}
	
	.chart-container::after {
	  content: '加载中...';
	  display: flex;
	  justify-content: center;
	  align-items: center;
	  height: 100%;
	}
</style>