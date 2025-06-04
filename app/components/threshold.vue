<template>
	  <view class="form-item">
	    <text class="label">{{target}}阈值({{unit}})</text>
		{{limit}}
	    <input 
	      type="number"
		  :value="displayValue"
		  @input="handleInput"
		  @blur="validateInput"
	      :placeholder="dynamicPlaceholder"
	      class="input"
		  :class="{'error-border': hasError}"
	    />
		<text v-if="hasError" class="error-message">{{ errorMessage }}</text>
	</view>
</template>

<script>
	export default {
		name:"threshold",
		props: {
			// 指标
			target: {
				type: String,
				default: ''
			},
			// 阈值
			modelValue: {
				type: Number,
				default: 0
			}
		},
		computed: {
		    unit() {
				const units = {
					'体感温度': '℃',
					'烟雾': 'ppm'
				};
				return units[this.target] || '';
		    },
			limit(){
				const limits = {
					'体感温度': '体感温度超过35℃存在危险，请勿超过35℃阈值',
					'烟雾': '烟雾浓度超过50ppm时存在危险，请勿超过50ppm阈值'
				};
				return limits[this.target] || '';
			},
			dynamicPlaceholder() {
				return `请输入${this.target}阈值`
			},
			thresholdRange() {
				const ranges = {
					'体感温度': { min: 0, max: 35 },
					'烟雾': { min: 0, max: 50 }
				};
				return ranges[this.target] || { min: 0, max: Infinity };
			}
		},
		data() {
			return {
				hasError: false,
				displayValue: this.modelValue,
				previousValue: this.modelValue,
				errorMessage: ''
			}
		},
		methods: {
		    handleInput(e) {
				this.displayValue = e.detail.value;
		    },
			validateInput() {
				const value = Number(this.displayValue);
				const range = this.thresholdRange;
				// 重置错误状态
				this.hasError = false;
				this.errorMessage = '';
				
				if (isNaN(value)) {
					this.showError('请输入有效的数字');
					return;
				}
				else if (value < range.min) {
					this.showError(`值不能小于${range.min}`);
					return;
				}
				else if (value > range.max) {
					this.showError(`值不能超过${range.max}`);
					return;
				}
				else {
					this.hasError = false;
					this.$emit('update:modelValue', value);
				}
			},
			showError(message) {
				this.hasError = true;
				this.errorMessage = message;
				setTimeout(() => {
					this.displayValue = this.previousValue;
				}, 500);
				
				// 自动清除错误状态
				setTimeout(() => {
					this.hasError = false;
				}, 3000);
			}
		},
		watch: {
			modelValue(newVal) {
				this.currentValue = newVal;
			}
		}
	}
</script>

<style scoped>
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
  border: 1rpx solid #bbb;
  padding: 20rpx;
  border-radius: 16rpx;
  font-size: 32rpx;
}

.error-border {
	border: 1rpx solid #ff0000 !important;
}
.error-message {
  display: block;
  color: #ff0000;
  font-size: 24rpx;
  margin-top: 8rpx;
}
</style>