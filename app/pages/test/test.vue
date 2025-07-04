<template>
  <view class="video-container">
    <view class="video-title">111</view>
  	<div v-if="true" id="mui-player" class="live-player" :key="playerKey">
	</div>
	<view v-else class="video-placeholder">
  		<image src="/static/images/视频断开.png" class="offline-image"/>
  		<text>视频连接已断开</text>
    </view>
  </view>
</template>
 
<script>
  import 'mui-player/dist/mui-player.min.css'
  import MuiPlayer from 'mui-player';
  import Flv from 'flv.js'
  export default {
    data() {
      return {
        mp: null,
		video_ready: false,
		playerKey: 0
      };
    },
    onShow(){
		this.$nextTick(()=>{
			// 初始化 MuiPlayer 插件，MuiPlayer 方法传递一个对象，该对象包括所有插件的配置
			this.mp = new MuiPlayer({
				container:document.getElementById("mui-player"),
				src:'http://47.93.33.13:80/live?port=1935&app=live&stream=stream',
				autoplay: true,
				live: true,
				parse:{
					type:'flv',
					loader:Flv,
					isLive: true,
					enableStashBuffer: false,
					config:{
						debug:true
					}
				},
				pageHead:false
			});
		});
    },
    onUnload(){
      this.mp.destroy()
    },
 }
</script>

<style>
	.video-container {
	  margin: 30rpx;
	  background: #fff;
	  border-radius: 20rpx;
	  box-shadow: 0 8rpx 20rpx 0 rgba(0, 0, 0, 0.1);
	  padding: 20rpx;
	}
	
	.video-title {
	  font-size: 34rpx;
	  font-weight: bold;
	  color: #333;
	  margin-bottom: 20rpx;
	  padding-left: 10rpx;
	}
	
	.live-player {
	  width: 100%;
	  height: 400rpx;
	  border-radius: 15rpx;
	  /* background: #000; */
	}
	
	.video-placeholder {
	  height: 400rpx;
	  display: flex;
	  flex-direction: column;
	  justify-content: center;
	  align-items: center;
	  background: #f5f5f5;
	  border-radius: 15rpx;
	}
	
	.offline-image {
	  width: 150rpx;
	  height: 150rpx;
	  margin-bottom: 20rpx;
	}
</style>