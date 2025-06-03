<template>
	  <view class="form-item">
	    <text class="label">{{target}}阈值({{unit}})</text>
	    <input 
	      type="number"
		  :value="displayValue"
		  @input="handleInput"
		  @blur="validateInput"
	      :placeholder="dynamicPlaceholder"
	      class="input"
		  :class="{'error-border': hasError}"
	    />
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
				if(this.target === '温度')
					return '℃'
				else if(this.target === '湿度')
					return '%RH'
				else if(this.target === '烟雾')
					return 'ppm'
		    },
			dynamicPlaceholder() {
				return `请输入${this.target}阈值`
			}
		},
		data() {
			return {
				hasError: false,
				displayValue: this.modelValue,
				previousValue: this.modelValue
			}
		},
		methods: {
		    handleInput(e) {
				this.displayValue = e.detail.value;
		    },
			validateInput() {
				const value = Number(this.displayValue);
				if (isNaN(value) || value < 0) {
					this.hasError = true;
					setTimeout(() => {
						this.displayValue = this.previousValue;
					}, 500);
					// 自动清除错误状态
					setTimeout(() => {
						this.hasError = false;
					}, 3000);
				} else {
					this.hasError = false;
					this.$emit('update:modelValue', Math.max(0, value));
				}
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
</style>