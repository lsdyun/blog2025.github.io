const express = require('express');
const fs = require('fs').promises;
const path = require('path');
const app = express();
const PORT = 3000;

// 数据库配置
const DB_PATH = path.join(__dirname, 'db.json');

// 中间件
app.use(express.json());
app.use(express.static('public')); // 托管静态文件

// 读取数据库
const readDB = async () => {
  try {
    const data = await fs.readFile(DB_PATH, 'utf-8');
    return JSON.parse(data);
  } catch (err) {
    if (err.code === 'ENOENT') {
      await fs.writeFile(DB_PATH, JSON.stringify({ users: [] }, null, 2));
      return { users: [] };
    }
    throw err;
  }
};

// 写入数据库
const writeDB = async (data) => {
  await fs.writeFile(DB_PATH, JSON.stringify(data, null, 2), 'utf-8');
};

// RESTful API
app.get('/api/users', async (req, res) => {
  try {
    const db = await readDB();
    res.json(db.users);
  } catch (err) {
    res.status(500).send('Database error');
  }
});

app.post('/api/users', async (req, res) => {
  try {
    const db = await readDB();
    const newUser = { id: Date.now(), ...req.body };
    db.users.push(newUser);
    await writeDB(db);
    res.status(201).json(newUser);
  } catch (err) {
    res.status(500).send('Create failed');
  }
});

app.put('/api/users/:id', async (req, res) => {
  try {
    const db = await readDB();
    const user = db.users.find(u => u.id === parseInt(req.params.id));
    if (!user) return res.status(404).send('User not found');
    
    Object.assign(user, req.body);
    await writeDB(db);
    res.json(user);
  } catch (err) {
    res.status(500).send('Update failed');
  }
});

app.delete('/api/users/:id', async (req, res) => {
  try {
    const db = await readDB();
    const initialLength = db.users.length;
    db.users = db.users.filter(u => u.id !== parseInt(req.params.id));
    
    if (db.users.length === initialLength) {
      return res.status(404).send('User not found');
    }
    
    await writeDB(db);
    res.status(204).send();
  } catch (err) {
    res.status(500).send('Delete failed');
  }
});

app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});
