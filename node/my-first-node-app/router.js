const router = {
  handleRequests(req, res) {
    const { url } = req;
    
    
    // 路由映射表
    const routes = {
      '/': () => {
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
        res.end('<h1>你好世界！</h1><p>这是我的第一个 Node.js 应用。</p>');
      },
      '/about': () => {
        res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end('关于我们');
      },
      '404': () => {
        res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end('404 页面不存在');
      }
    };

    // 执行匹配的路由处理函数，无匹配则返回404
    (routes[url] || routes['404'])();
  }
};

module.exports = router;
