/**
 * 子进程示例文件 - workers/io.js
 * 处理IO密集型任务
 */

const fs = require('fs');

process.on('message', async (msg) => {
  if (msg.type === 'PROCESS_FILE') {
    try {
      const data = await fs.promises.readFile(msg.filePath);
      // 处理文件内容...
      process.send({ status: 'success' });
    } catch (err) {
      process.send({ status: 'error', err });
    }
  }
});