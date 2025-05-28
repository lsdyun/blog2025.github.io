/* const buf = Buffer.from('测试', 'utf8');

// 输出 72756e6f6f62
console.log(buf.toString('hex'));

// 输出 cnVub29i
console.log(buf.toString('base64')); */

/* 
buf = Buffer.alloc(10,"","utf8");
len = buf.write("测试测试测试测试测试");

console.log("写入字节数 : "+  len); */

/* const buf = Buffer.alloc(10,"","utf8");
buf.write("测试测试测试测试测试");
for(var i = 0; i < 10 ; i++){
    buf[i] = i+97;
}
console.log(buf.toString('utf8'));// 输出 */

/* const buf = Buffer.alloc(10);
// 在 write() 方法中显式指定编码
buf.write("测试测试测试测试测试", 0, buf.length, "utf8");

console.log(buf.toString('utf8'));// 输出 */
/* 
const buf = Buffer.alloc(10);
// 在 write() 方法中显式指定编码和写入长度
buf.write("测试测试测试测试测试", 0, buf.length, "utf8");

console.log(buf.toString('utf8', 0 , 3));// 输出 "测试测" */

/* 
const buf = Buffer.alloc(10);
// 在 write() 方法中显式指定编码和写入长度
buf.write("测试测试测试测试测试", 0, buf.length, "utf8");

console.log( buf.toString(undefined));// 输出 "测" */

/* var buffer1 = Buffer.from(('测试'));
var buffer2 = Buffer.from(('test'));
var buffer3 = Buffer.concat([buffer1,buffer2]);
console.log("buffer3 内容: " + buffer3.toString()); */

/* var buffer1 = Buffer.from('ABC');
var buffer2 = Buffer.from('ABCD');
var result = buffer1.compare(buffer2);

console.log(result);

if(result < 0) {
   console.log(buffer1 + " 在 " + buffer2 + "之前");
}else if(result == 0){
   console.log(buffer1 + " 与 " + buffer2 + "相同");
}else {
   console.log(buffer1 + " 在 " + buffer2 + "之后");
} */

/* const buf1 = Buffer.from("测试测试测试", "utf8"); // 18 字节
const buf2 = Buffer.from("哈哈", "utf8"); // 6 字节

// 创建新 Buffer，总长度 = buf1长度 + buf2长度
const newBuf = Buffer.alloc(buf1.length + buf2.length);

// 复制原 buf1 的前 3 字节（"测"）
buf1.copy(newBuf, 0, 0, 3); 
// 插入 buf2（"哈哈"）
buf2.copy(newBuf, 3); 
// 复制原 buf1 的剩余字节（从第 3 字节到末尾）
buf1.copy(newBuf, 3 + buf2.length, 3); 

console.log(newBuf.toString()); // 输出：测哈哈测试测试测试 */


/* const buf1 = Buffer.from("abc");
const buf2 = Buffer.from('ABC');

//将 buf2 插入到 buf1 指定位置上
buf2.copy(buf1, 2);

console.log(buf1.toString()); */

/* var buffer1 = Buffer.from('test');
// 剪切缓冲区
var buffer2 = buffer1.slice(0,2);
console.log("buffer2的内容为: " + buffer2.toString()); */

var buffer = Buffer.from('test');
//  缓冲区长度
console.log("buffer 长度为: " + buffer.length);