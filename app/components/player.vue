<template>
	<view class="video-container">
	  <view class="video-title">{{title}}</view>
		<div id="mui-player" v-if="video_ready" class="live-player" :key="playerKey"></div>
		<view v-else class="video-placeholder">
			<image src="/static/images/视频断开.png" class="offline-image"/>
			<text>视频连接已断开</text>
	    </view>
	</view>
</template>

<script>
	import 'mui-player/dist/mui-player.min.css'
	import MuiPlayer from 'mui-player'
	import Flv from 'flv.js'
	import Hls from 'hls.js'

	export default {
		name:"player",
		props: {
			// 播放标题
			title: {
				type: String,
				default: '实时监控'
			},
			// 播放地址
			src: {
				type: String,
				default: 'http://47.93.33.13:80/live?port=1935&app=live&stream=stream'
			},
			// 播放格式
			type: {
				type: String,
				default: 'hls'
			},
			// 自动播放
			autoplay: {
				type: Boolean,
				default: true
			},
			// 循环播放
			loop: {
				type: Boolean,
				default: true
			},
			// 静音播放
			muted: {
				type: Boolean,
				default: false
			},
			// 播放器容器是否自适应视频高度
			autoFit: {
				type: Boolean,
				default: false
			},
			// 直播模式
			live: {
				type: Boolean,
				default: true
			}
		},
		data() {
			return {
				mp: {},
				checkStreamInterval: null,
				video_ready: false,
				playerKey: 0
			};
		},
		mounted() {
			this.startStreamCheck();
		},
		methods: {
			init() {
				this.$nextTick(()=>{
					this.mp = new MuiPlayer({
						container:document.getElementById("mui-player"),
						src: this.src,
						autoplay: true,
						muted: true,
						live: true,
						parse:{
							type: 'flv',
							loader: Flv,
							isLive: true,
							enableStashBuffer: false,
							config: { debug: true }
						},
						pageHead:false
					});
				});				
			},
			// 启动流检测
			startStreamCheck() {
				this.checkStreamInterval = setInterval(() => {
					this.checkStreamExists()
				}, 5000) // 5秒检测一次
				this.checkStreamExists() // 立即执行首次检测
			},
			// 清除检测定时器
			clearCheckInterval() {
			  if (this.checkStreamInterval) {
				clearInterval(this.checkStreamInterval);
				this.checkStreamInterval = null;
			  }
			},
			// 检测流是否存在
			async checkStreamExists() {
				try {
					const res = await uni.request({
						url: 'http://47.93.33.13:80/stat' // Nginx状态接口
					});
					if (res.statusCode === 200) {
						const parser = new DOMParser()
						const xmlDoc = parser.parseFromString(res.data, "text/xml")
				  
						// 解析XML查找流
						const streamNodes = xmlDoc.querySelectorAll('stream')
						const foundStream = Array.from(streamNodes).some(stream => {
							const name = stream.querySelector('name')?.textContent
							const publishing = stream.querySelector('publishing')
							return name === 'stream' && publishing !== null // 匹配流名称
						});
		
						// console.log(foundStream)
						if (foundStream) {
							console.log(foundStream)
							this.clearCheckInterval();
							this.video_ready = true;
							this.playerKey = Date.now();
							this.init()
						}
					}
				} catch (err) {
					console.error('流检测失败:', err);
				}
			}
		}
	}
</script>

<style scoped>
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
	  background: #000;
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