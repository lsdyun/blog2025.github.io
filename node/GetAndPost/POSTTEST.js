const http = require('http');

const server = http.createServer((req, res) => {
  if (req.method === 'POST') {
    let body = [];
    // 监听 data 事件，逐块接收数据
    /* req.on('data', chunk => body.push(chunk));  // 分块接收数据
    // 监听 end 事件，数据接收完毕
    req.on('end', () => {
      body = Buffer.concat(body).toString();
      res.end(`接收数据：${body}`);
    }); */
    req.on('end', () => {
        try {
          const jsonData = JSON.parse(body);  // 直接解析
          res.end(JSON.stringify({ status: 'success', data: jsonData }));
        } catch (e) {
          res.statusCode = 400;
          res.end('Invalid JSON');
        }
      });
  }
});

server.listen(3000);