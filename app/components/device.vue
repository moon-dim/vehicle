<template>
	<view class="status-panel">
	  <view class="device-item">
	    <image class="status-icon" :src="statusImage"></image> 
	    <text class="device-name">{{name}}</text>
	    <view class="status-container">
			<text class="status-text {{isOnline ? 'online' : 'offline'}}">
				{{isOnline ? '在线' : '离线'}}
			</text>
			<text v-if="!isOnline" class="last-active">
				最后活跃：{{ formattedLastActive }}
			</text>
		</view>
	  </view>
	</view>
</template>

<script>
	export default {
		name:"device",
		props: {
			name: {
				type: String,
				default: "主控设备"
			},
			isOnline: {
				type: Boolean,
				default: false
			},
			lastActive: {
				type: Number,
				default: 0
			}
		},
		computed: {
			statusImage() {
				return this.isOnline 
					? '/static/images/online.png' 
					: '/static/images/offline.png';
			},
			formattedLastActive(){
				const date = new Date(this.lastActive)
				const year = date.getFullYear()
				const month = String(date.getMonth() + 1).padStart(2, '0')
				const day = String(date.getDate()).padStart(2, '0')
				const hour = String(date.getHours()).padStart(2, '0')
				const minute = String(date.getMinutes()).padStart(2, '0')
				const second = String(date.getSeconds()).padStart(2, '0')
				return `${year}:${month}:${day} ${hour}:${minute}:${second}`
			}
		},
	}
</script>

<style scoped>
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
	  margin-right: 20rpx;
	}
	
	.status-container {
	  display: flex;
	  flex-direction: column;
	  align-items: flex-end;
	  /* margin-top: 8rpx; */
	}
	
	.status-text {
	  min-width: 100rpx;
	  /* height: 30px; */
	  line-height: 10px;
	  line-height: 1.4;
	  text-align: center;
	  font-size: 26rpx;
	  margin-right: 20rpx;
	}
	
	.last-active {
	  font-size: 24rpx;
	  color: #999;
	  /* margin-top: 4rpx; */
	  white-space: nowrap;
	  /* line-height: 1.4; */
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
</style>