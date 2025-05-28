const net = require('net');
const readline = require('readline');

// 连接服务器
const client = net.connect({ port: 8000 }, () => {
  console.log('已连接到服务器');


  // 输入消息并发送（双工写操作）
/*   rl.question('请输入要发送的消息（输入 exit 退出）: ', (message) => {
    client.write(message);
    rl.close();
  }); */
});

  // 创建命令行交互接口
const rl = readline.createInterface({
   input: process.stdin,
   output: process.stdout
});

// 持续监听输入
const askQuestion = () => {
    rl.question('请输入消息（输入 exit 退出）: ', (message) => {
      if (message.toLowerCase() === 'exit') {
        client.end();
        rl.close();
        return;
      }
      client.write(message);
      askQuestion(); // 递归调用，持续输入
    });
  };

// 接收服务器响应（双工读操作）
/* client.on('data', (data) => {
    console.log(`服务器响应: ${data.toString()}`);
    // 收到响应后主动关闭连接（可选）
    client.end(); 
}); */
client.on('connect', () => {
    askQuestion(); // 连接成功后启动输入循环
});

// 监听连接关闭
client.on('end', () => {
  console.log('连接已关闭');
});

// 错误处理
client.on('error', (err) => {
  console.error('客户端错误:', err.message);
});
