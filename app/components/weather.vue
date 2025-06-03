<template>
	<view class="weather">
	  <view class="weather_image_view">
	    <image :src="weatherInfo.imageUrl" class="weather_image" mode="widthFix"></image>
	  </view>
	  <view class="weather_info_view">
	    <view class="location_view">
	      <image src="/static/images/location.png" mode="widthFix" class="location_image"></image>
	      <text class="location_info">{{weatherInfo.province}} {{weatherInfo.city}}</text>
	    </view>
	    <view class="temp_info">{{weatherInfo.weather}} {{weatherInfo.temperature}}℃</view>
	    <view class="wind_info">湿度 {{weatherInfo.humidity}}% | 风力{{weatherInfo.windpower}}级</view>
	  </view>
	</view>
</template>

<script>
	const KEY = "47cb7d22ce321d60ae38b98c0b56e17e";
	export default {
		name:"weather",
		data() {
			return {
				weatherInfo: {}
			};
		},
		mounted() {
		    this.getLocation()
		},
		methods: {
			getLocation() {
				let that = this
				uni.getLocation({
					type: 'wgs84',
					success(res) {
						console.log(res)
						const latitude = res.latitude
						const longitude = res.longitude
						const speed = res.speed
						const accuracy = res.accuracy
						uni.request({
							url: 'https://restapi.amap.com/v3/geocode/regeo?parameters',
							data: {
								key: KEY,
								location: longitude + "," + latitude
							},
							success(res) {
								console.log(res)
								let cityCode = res.data.regeocode.addressComponent.adcode
								uni.request({
									url: 'https://restapi.amap.com/v3/weather/weatherInfo?parameters',
									data: {
										key: KEY,
										city: cityCode
									},
									success(res) {
										console.log(res)
										let weather_info = res.data.lives[0]
										weather_info.imageUrl = "/static/images/weather/" + that.getIconKey(weather_info.weather) + ".png"
										that.weatherInfo = weather_info
									}
								})
							}
						})
					}
				})
			},
			
			getIconKey(weather) {
				const iconWeatherMap = {
					'风': ['有风', '平静', '微风', '和风', '清风', '强风/劲风', '疾风', '大风', '烈风', '风暴', '狂爆风', '飓风', '热带风暴', '龙卷风'],
					'多云': ['少云', '晴间多云', '多云'],
					'雪': ['雪', '阵雪', '小雪', '中雪', '大雪', '暴雪', '小雪-中雪', '中雪-大雪', '大雪-暴雪', '冷'],
					'雾': ['浮尘', '扬沙', '沙尘暴', '强沙尘暴', '雾', '浓雾', '强浓雾', '轻雾', '大雾', '特强浓雾'],
					'晴': ['晴', '热'],
					'雨夹雪': ['雨雪天气', '雨夹雪', '阵雨夹雪'],
					'雨': ['阵雨', '雷阵雨', '雷阵雨并伴有冰雹', '小雨', '中雨', '大雨', '暴雨', '大暴雨', '特大暴雨', '强阵雨', '强雷阵雨', '极端降雨', '毛毛雨/细雨', '雨', '小雨-中雨', '中雨-大雨', '大雨-暴雨', '暴雨-大暴雨', '大暴雨-特大暴雨', '冻雨'],
					'阴': ['阴', '霾', '中度霾', '重度霾', '严重霾', '未知']
				}
				// 这个是默认值
				let iconKey = '阴'
				for (const weatherKey in iconWeatherMap) {
					if (Object.hasOwnProperty.call(iconWeatherMap, weatherKey)) {
						const weatherNames = iconWeatherMap[weatherKey]
						const findWeatherItem = weatherNames.find(name => weather === name)
						if (findWeatherItem) {
							iconKey = weatherKey
							break
						}
					}
				}
				return iconKey
			}
		}
	}
</script>

<style>
	.weather {
	  display: flex;
	  box-shadow: 0 8rpx 20rpx 0 rgba(0, 0, 0, 0.3);
	  height: 250rpx;
	  border-radius: 32rpx;
	  margin: 38rpx 32rpx;
	  background-color: #ffffff;
	}
	
	.weather_image_view {
	  display: flex;
	  width: 40%;
	  align-items: center;
	}
	
	.weather_image {
	  width: 200rpx;
	  margin-left: 50rpx;
	}
	
	.weather_info_view {
	  display: flex;
	  flex-direction: column;
	  align-items: center;
	}
	
	.location_view {
	  margin-top: 40rpx;
	}
	
	.location_image {
	  width: 20rpx;
	}
	
	.location_info {
	  font-size: 24rpx;
	  margin-left: 10rpx;
	}
	
	.temp_info {
	  font-size: 70rpx;
	  margin-top: 10rpx;
	}
	
	.wind_info {
	  font-size: 24rpx;
	  margin-top: 10rpx;
	}
</style>