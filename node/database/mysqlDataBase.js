const mysql = require('mysql2/promise');

// 数据库配置
const dbConfig = {
  host: 'localhost',
  user: 'root',
  password: 'root',
  database: 'testdb',
  waitForConnections: true,
  connectionLimit: 10,
  queueLimit: 0
};

// 创建连接池
const pool = mysql.createPool(dbConfig);

// 增删改查操作封装
class UserDAO {
  // 添加用户
  static async addUser(username, email) {
    const sql = 'INSERT INTO users (username, email) VALUES (?, ?)';
    const [result] = await pool.execute(sql, [username, email]);
    return result.insertId;
  }

  // 查询所有用户
  static async getAllUsers() {
    const sql = 'SELECT * FROM users';
    const [rows] = await pool.query(sql);
    return rows;
  }

  // 更新用户
  static async updateUser(id, newEmail) {
    const sql = 'UPDATE users SET email = ? WHERE id = ?';
    const [result] = await pool.execute(sql, [newEmail, id]);
    return result.affectedRows;
  }

  // 删除用户
  static async deleteUser(id) {
    const sql = 'DELETE FROM users WHERE id = ?';
    const [result] = await pool.execute(sql, [id]);
    return result.affectedRows;
  }
}

// 测试示例
(async () => {
  try {
    // 添加用户
    const newUserId = await UserDAO.addUser('new_user', 'new@example.com');
    console.log(`添加成功，用户ID: ${newUserId}`);

    // 查询所有用户
    const users = await UserDAO.getAllUsers();
    console.log('当前用户列表:', users);

    // 更新用户
    const updatedRows = await UserDAO.updateUser(newUserId, 'updated@example.com');
    console.log(`更新影响行数: ${updatedRows}`);

    // 删除用户
    const deletedRows = await UserDAO.deleteUser(newUserId);
    console.log(`删除影响行数: ${deletedRows}`);

    // 最终用户列表
    const finalUsers = await UserDAO.getAllUsers();
    console.log('最终用户列表:', finalUsers);

  } catch (error) {
    console.error('操作失败:', error);
  } finally {
    // 关闭连接池
    await pool.end();
  }
})();
