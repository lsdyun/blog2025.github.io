const http = require('http');
const url = require('url');

const server = http.createServer((req, res) => {
  if (req.method === 'GET') {
    const parsedUrl = url.parse(req.url, true); // 解析路径和查询参数
    const { pathname, query } = parsedUrl;

    res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
    res.end(`GET 路径：${pathname}\n参数: ${JSON.stringify(query)}`);
  }
});

server.listen(3000);