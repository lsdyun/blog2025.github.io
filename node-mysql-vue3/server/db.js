// db.js - 数据库连接池
const mysql = require('mysql2/promise');

const pool = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'root',
  database: 'testdb',
  waitForConnections: true,
  connectionLimit: 10
});

module.exports = pool;
