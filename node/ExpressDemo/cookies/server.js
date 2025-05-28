// app.js
const express = require('express');
const cookieParser = require('cookie-parser');
const app = express();
const port = 3000;

// 配置 Cookie 中间件（启用签名）
app.use(cookieParser('your_secret_key'));

// 基础路由（测试页面）
app.get('/', (req, res) => {
  res.send(`
    <html>
      <body style="padding: 20px;">
        <h2>Cookie 管理测试</h2>
        <button onclick="location.href='/set-cookie'">设置 Cookie</button>
        <button onclick="location.href='/get-cookie'">读取 Cookie</button>
        <button onclick="location.href='/clear-cookie'">删除 Cookie</button>
        <p style="color: green">${req.signedCookies.user ? `当前用户: ${req.signedCookies.user}` : ''}</p>
      </body>
    </html>
  `);
});

// 设置签名 Cookie
app.get('/set-cookie', (req, res) => {
  res.cookie('user', 'Alice', {
    maxAge: 60 * 60 * 1000,    // 1 小时有效期
    httpOnly: true,            // 禁止客户端脚本访问
    secure: false,             // 开发环境设为 false，生产环境需设为 true
    signed: true               // 启用签名防篡改
  });
  res.redirect('/');
});

// 读取 Cookie
app.get('/get-cookie', (req, res) => {
  const unsignedUser = req.cookies.user;        // 未签名 Cookie
  const signedUser = req.signedCookies.user;    // 签名 Cookie
  
  if (signedUser === false) {                   // 签名校验失败处理
    res.clearCookie('user');
    return res.send('Cookie 签名校验失败，已清除');
  }
  res.send(`签名 Cookie: ${signedUser || '无'}<br>普通 Cookie: ${unsignedUser || '无'}`);
});

// 删除 Cookie
app.get('/clear-cookie', (req, res) => {
  res.clearCookie('user', { 
    path: '/', 
    signed: true 
  });
  res.redirect('/');
});

// 错误处理
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).send('服务器错误');
});

app.listen(port, () => {
  console.log(`运行地址: http://localhost:${port}`);
});
