/* var fs = require('fs');
var data = '';
// 创建可读流
var readerStream = fs.createReadStream('input.txt','UTF8');

// 处理流事件 --> data, end, and error
readerStream.on('data',function(chunk){
    readerStream.pause();//暂停读取
    setTimeout(()=>{
        readerStream.resume();//恢复读取
        data += chunk;
        console.log("程序执行完毕");
    },3000)
});

readerStream.on('end',function(){
    console.log(data);
});
 */

var fs = require('fs');
var data = '';
// 创建可读流
var readerStream = fs.createReadStream('input.txt','UTF8');

// 处理流事件 --> data, end, and error
readerStream.on('data',(chunk)=>{
    readerStream.destroy()//销毁流
});
