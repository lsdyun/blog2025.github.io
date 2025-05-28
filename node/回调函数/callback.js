/* // 阻塞回调示例（同步读取文件）
var fs = require("fs");
const data = fs.readFileSync('input.txt');  // 主线程暂停
console.log(data.toString());              // 需等待文件读取完成
console.log("程序执行结束");   */

var fs = require("fs");
// 非阻塞回调示例（异步读取文件）
fs.readFile('input.txt', (err, data) => {   // 立即返回，主线程继续
  if (err) throw err;
  console.log(data.toString());            // 在回调中处理结果
});
console.log("程序执行结束");               // 先执行此行