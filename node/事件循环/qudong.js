const EventEmitter = require('events');  
const myEmitter = new EventEmitter();  

// 注册事件监听器  
myEmitter.on('userAction', (data) => {  
  console.log(`捕获用户行为：${data}`);  
});  

// 触发事件  
myEmitter.emit('userAction', '点击按钮');  