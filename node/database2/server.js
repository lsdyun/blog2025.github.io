// server.js - 主服务
const express = require('express');
const cors = require('cors');
const app = express();
const usersRouter = require('./users');

// 中间件
app.use(cors());
app.use(express.json());

// 路由
app.use('/api/users', usersRouter);

// 启动服务
const PORT = 3001;
app.listen(PORT, () => {
  console.log(`API 服务运行在 http://localhost:${PORT}`);
});
