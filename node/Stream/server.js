const net = require('net');

// 创建 TCP 服务器
const server = net.createServer((socket) => {
  console.log('客户端已连接');

  // 监听客户端发送的数据
  socket.on('data', (data) => {
    const clientMessage = data.toString().trim();
    console.log(`收到客户端消息: ${clientMessage}`);

    // 向客户端发送响应（双工写操作）
    socket.write(`服务器已收到: "${clientMessage}"\n`);
  });

  // 监听客户端断开连接
  socket.on('end', () => {
    console.log('客户端已断开连接');
  });

  // 错误处理
  socket.on('error', (err) => {
    console.error('服务器端错误:', err.message);
  });
});

// 监听 8000 端口
server.listen(8000, () => {
  console.log('服务器已启动，监听端口 8000');
});
