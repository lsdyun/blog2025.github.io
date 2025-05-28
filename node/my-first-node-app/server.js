const http = require('http');
const router = require('./router'); // 导入路由模块

const server = http.createServer((req, res) => {
  // 设置默认字符集（UTF-8保证中文不亂碼）
  res.setHeader('Content-Type','text/html; charset=utf-8');
  
  // 将请求交给路由处理
  router.handleRequests(req, res);
});

const PORT = 3000;
server.listen(PORT, () => {
  console.log(`服务器已启动: http://localhost:${PORT}`);
});
