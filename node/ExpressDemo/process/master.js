/**
 * 多进程模板 - 主进程文件 master.js
 * 运行命令: node master.js
 */

const { fork } = require('child_process');
const cluster = require('cluster');
const os = require('os');

// 场景1：使用 child_process.fork 创建专用子进程
if (cluster.isMaster) {
  // 创建第一个子进程 - 处理计算任务
  const computeWorker = fork('./workers/compute.js');
  
  // 创建第二个子进程 - 处理IO任务
  const ioWorker = fork('./workers/io.js');

  // 主进程向计算子进程发送任务
  computeWorker.send({ 
    type: 'CALC_FIB', 
    value: 40 
  });

  // 接收计算子进程的结果
  computeWorker.on('message', msg => {
    console.log(`[主进程] 收到计算结果: ${msg.result}`);
  });

  // 监听子进程退出事件
  computeWorker.on('exit', code => {
    console.log(`计算进程退出，代码: ${code}`);
  });

  // 场景2：使用 cluster 模块创建HTTP服务集群
  if (cluster.isPrimary) {
    const cpuCores = os.cpus().length;
    console.log(`启动 ${cpuCores} 个工作进程`);

    // 根据CPU核心数创建子进程
    for (let i = 0; i < cpuCores; i++) {
      cluster.fork(); // 每个子进程都会执行else部分的代码
    }

    // 监听工作进程退出事件
    cluster.on('exit', worker => {
      console.log(`工作进程 ${worker.process.pid} 已退出`);
      // 可选：自动重启新进程
      cluster.fork();
    });
  }
} else {
  // Cluster工作进程执行的HTTP服务代码
  const express = require('express');
  const app = express();
  
  app.get('/', (req, res) => {
    // 显示当前进程PID
    res.send(`响应来自进程: ${process.pid}`);
  });

  app.listen(3000, () => {
    console.log(`工作进程 ${process.pid} 已启动`);
  });
}



