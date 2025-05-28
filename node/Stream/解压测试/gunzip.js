const zlib = require('zlib');
const fs = require('fs');

// 创建一个可读流（读取.gz文件）
const readableStream = fs.createReadStream('input.txt.gz');

// 创建解压转换流
const gzip = zlib.createGunzip();

// 创建一个可写流（输出解压后的文件）
const writableStream = fs.createWriteStream('input副本.txt');

// 将可读流管道到转换流，再管道到可写流（管道连接）
readableStream.pipe(gzip).pipe(writableStream);

// 监听完成事件
writableStream.on('finish', () => {
    console.log('文件压缩成功！');
});

// 错误处理（重要！）
readableStream.on('error', (err) => console.error('读取失败:', err));
gzip.on('error', (err) => console.error('解压失败:', err));
writableStream.on('error', (err) => console.error('写入失败:', err));