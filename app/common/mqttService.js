import mqtt from 'mqtt/dist/mqtt.min.js'
import HmacSHA1 from 'crypto-js/hmac-sha1'

let mqttAccountInfo = {
	productKey: "k1tj8GglYHx",
	deviceName: "app1",
	deviceSecret: "fe890d71daa94c811cb7df7305de1833"
}
let client = null

// 初始化MQTT配置
const initMqttOptions = () => {
  const params = {
    productKey: mqttAccountInfo.productKey,
    deviceName: mqttAccountInfo.deviceName,
    deviceSecret: mqttAccountInfo.deviceSecret,
    clientId: `${mqttAccountInfo.productKey}.${mqttAccountInfo.deviceName}`, // 修复clientId生成
    timestamp: Date.now()
  }

  const contentStr = `clientId${params.clientId}deviceName${params.deviceName}productKey${params.productKey}timestamp${params.timestamp}`
  const clientId = `${params.clientId}|securemode=2,signmethod=hmacsha1,timestamp=${params.timestamp}|`
  const username = `${params.deviceName}&${params.productKey}`
  const password = HmacSHA1(contentStr, params.deviceSecret).toString()
  
  const options = {
  	wsOptions: {},
  	protocolVersion: 4, //MQTT连接协议版本
  	clientId: clientId,
  	keepalive: 60,
  	clean: false,
  	username: username,
  	password: password,
  	reconnectPeriod: 1000, //1000毫秒，两次重新连接之间的间隔
  	connectTimeout: 30 * 1000, //1000毫秒，两次重新连接之间的间隔
  	resubscribe: true //如果连接断开并重新连接，则会再次自动订阅已订阅的主题（默认true）
  }

  return options;
}


// 核心功能封装
const mqttService = {
  // 连接MQTT
  connect: () => {
    if (client) {
      console.log('已存在有效连接')
      return
    }

    const options = initMqttOptions(mqttAccountInfo)
    client = mqtt.connect('wss://iot-06z00frhc9ej8p2.mqtt.iothub.aliyuncs.com', options)

    client.on('connect', () => {
      console.log('连接服务器成功')
      mqttService.subscribe()
    })
	

    client.on('close', () => {
      console.log('连接关闭，自动重连中...')
    })

    client.on('error', (err) => {
      console.error('连接错误:', err)
    })
  },

  // 订阅主题
  subscribe: () => {
    if (!client) return
    client.subscribe(
      `/${mqttAccountInfo.productKey}/${mqttAccountInfo.deviceName}/user/get`,
      (err) => err ? console.error('订阅失败:', err) : console.log('订阅成功')
    )
  },

  // 发布消息
  publish: (payload) => {
    if (!client?.connected) {
      console.log('未建立有效连接')
      return
    }
	
    const topic = `/${mqttAccountInfo.productKey}/${mqttAccountInfo.deviceName}/user/update`
    client.publish(topic, JSON.stringify(payload), { qos: 1 }, (error) => {
		console.log(error || '消息发布成功');
    })
  },

  // 断开连接
  disconnect: () => {
    if (client) {
		client.end()
		client = null
		console.log('已断开连接')
    }
  },

  // 消息处理
  handleMessage: (context, messageHandler) => {
    if (!client) return
    
    client.on('message', (topic, message) => {
      try {
        const receiveData = JSON.parse(message.toString())
        messageHandler(topic, receiveData)
      } catch (error) {
        console.error('消息处理失败:', error)
      }
    })
  }
}

// 导出模块
export default {
  ...mqttService,
}