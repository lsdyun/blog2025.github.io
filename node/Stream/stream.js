/* var fs = require('fs');
var data = '';

// 创建可读流
var readerStream = fs.createReadStream('input.txt');

// 设置编码为 utf8。
readerStream.setEncoding('UTF8');

// 处理流事件 --> data, end, and error
readerStream.on('data',function(chunk){
    data += chunk;
});


readerStream.on('data',(chunk)=>{
    data += chunk;
});

readerStream.on('end',function(){
    console.log(data);
});

readerStream.on('end',()=>{
    console.log(data);
});

readerStream.on('error',function(err){
    console.log(err.stack);
}) 

readerStream.on('error',(err)=>{
    console.log(err.stack);
})

console.log("程序执行完毕");
 */

/* var fs = require('fs');
var data = '流的写入测试';

// 创建一个可以写入的流，写入到文件 output.txt 中
var writerStream = fs.createWriteStream('input.txt',{flags:'a'});

// 设置编码为 utf8。
writerStream.write(data,'UTF8');

// 标记文件末尾
writerStream.end();

// 处理流事件 --> finish、error
writerStream.on('finish', function() {
    console.log("写入完成。");
});

writerStream.on('error', function(err){
    console.log(err.stack);
 });
 
 console.log("程序执行完毕"); */

 const net = require('net');

// 创建一个 TCP 服务器
/* const server = net.createServer((socket) => {
    console.log('Client connected.');

    // 读取客户端数据
    socket.on('data', (data) => {
        console.log('Received data:', data.toString());
    });

    // 向客户端发送数据
    socket.write('Hello, Client!\n');

    // 监听关闭事件
    socket.on('end', () => {
        console.log('Client disconnected.');
    });
});

server.listen(3000, () => {
    console.log('Server listening on port 3000.');
}); */

