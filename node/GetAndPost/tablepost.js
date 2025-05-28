const http = require('http');
const querystring = require('querystring');

const server = http.createServer((req, res) => {
  if (req.method === 'POST' && req.url === '/submit') {
    let body = [];
    // 分块接收数据:ml-citation{ref="2,5" data="citationList"}
    req.on('data', chunk => body.push(chunk))
       .on('end', () => {
         const data = querystring.parse(Buffer.concat(body).toString());
         if (!data.username || !data.password) {
           res.writeHead(400, { 'Content-Type': 'application/json' });
           return res.end(JSON.stringify({ error: '参数缺失' }));
         }
         res.writeHead(200, { 'Content-Type': 'application/json' });
         res.end(JSON.stringify({ status: 'success', data }));
       });
  } else {
    res.statusCode = 404;
    res.end('Not Found');
  }
});

server.listen(3000, () => {
  console.log('原生服务运行于 http://localhost:3000');
});
