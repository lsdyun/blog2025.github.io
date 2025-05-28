/**
 * 子进程示例文件 - workers/compute.js
 * 处理CPU密集型任务
 */

// 接收主进程消息
process.on('message', (msg) => {
    if (msg.type === 'CALC_FIB') {
      const result = fibonacci(msg.value);
      process.send({ result }); // 发送结果回主进程
    }
  });
  
  // 斐波那契数列计算函数
  function fibonacci(n) {
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
  }
  