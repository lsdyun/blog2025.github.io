var http = require("http");
http.createServer(function(request,response){
    response.writeHead(200,{'Content-Type':'text/plain'})
    response.end('Hello World\n');

}).listen(8888);
console.log('服务器正在启动...\n')
console.log('服务器运行在 http://127.0.0.1:8888/');