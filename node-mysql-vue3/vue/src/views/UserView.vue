<template>
  <div class="container">
    <h1>用户管理</h1>

    <!-- 添加用户表单 -->
    <div class="add-user-form">
      <h2>添加新用户</h2>
      <form @submit.prevent="createUser">
        <div class="form-group">
          <label>用户名:</label>
          <input v-model="newUser.username" type="text" required />
        </div>
        <div class="form-group">
          <label>邮箱:</label>
          <input v-model="newUser.email" type="email" required />
        </div>
        <button type="submit">添加用户</button>
      </form>
    </div>

    <!-- 用户列表 -->
    <div class="user-list">
      <h2>用户列表</h2>
      <table>
        <thead>
          <tr>
            <th>ID</th>
            <th>用户名</th>
            <th>邮箱</th>
            <th>操作</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="user in users" :key="user.id">
            <td>{{ user.id }}</td>
            <td>{{ user.username }}</td>
            <td>
              <span v-if="!user.editing">{{ user.email }}</span>
              <input 
                v-else 
                v-model="user.editedEmail" 
                type="email" 
                required
              />
            </td>
            <td>
              <button 
                v-if="!user.editing"
                @click="startEdit(user)"
              >
                编辑
              </button>
              <div v-else class="edit-actions">
                <button @click="saveEdit(user)">保存</button>
                <button @click="cancelEdit(user)">取消</button>
              </div>
              <button @click="deleteUser(user.id)">删除</button>
            </td>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import axios from 'axios'

//const API_URL = 'http://localhost:3001/api/users'
/* 
如果 process.env.VUE_APP_API_BASE_URL 存在且为真值（truthy value），则使用该值 
如果环境变量未定义（undefined）、空字符串（''）、null 或其他假值（falsy），则使用 '/api'
*/
const API_BASE = process.env.VUE_APP_API_BASE_URL || '/api'
const API_URL = `${API_BASE}/users`


// 用户数据
const users = ref([])
const newUser = ref({
  username: '',
  email: ''
})

// 初始化获取用户列表
onMounted(async () => {
  await fetchUsers()
})

// 获取所有用户
const fetchUsers = async () => {
  try {
    const response = await axios.get(API_URL)
    users.value = response.data.map(user => ({
      ...user,
      editing: false,
      editedEmail: user.email
    }))
  } catch (error) {
    alert('获取用户列表失败：' + error.message)
  }
}

// 创建用户
const createUser = async () => {
  try {
    await axios.post(API_URL, newUser.value)
    await fetchUsers()
    newUser.value = { username: '', email: '' }
    alert('用户创建成功')
  } catch (error) {
    alert('创建用户失败：' + error.response?.data?.error || error.message)
  }
}

// 开始编辑
const startEdit = (user) => {
  user.editing = true
  user.editedEmail = user.email
}

// 取消编辑
const cancelEdit = (user) => {
  user.editing = false
  user.editedEmail = user.email
}

// 保存编辑
const saveEdit = async (user) => {
  try {
    await axios.put(`${API_URL}/${user.id}`, {
      email: user.editedEmail
    })
    user.email = user.editedEmail
    user.editing = false
    alert('更新成功')
  } catch (error) {
    alert('更新失败：' + error.response?.data?.error || error.message)
  }
}

// 删除用户
const deleteUser = async (id) => {
  if (!confirm('确定要删除这个用户吗？')) return
  
  try {
    await axios.delete(`${API_URL}/${id}`)
    await fetchUsers()
    alert('用户删除成功')
  } catch (error) {
    alert('删除失败：' + error.response?.data?.error || error.message)
  }
}
</script>

<style scoped>
.container {
  max-width: 800px;
  margin: 0 auto;
  padding: 20px;
}

.add-user-form {
  margin-bottom: 40px;
  padding: 20px;
  background: #f5f5f5;
  border-radius: 8px;
}

.form-group {
  margin-bottom: 15px;
}

.form-group label {
  display: block;
  margin-bottom: 5px;
}

.form-group input {
  width: 100%;
  padding: 8px;
  border: 1px solid #ddd;
  border-radius: 4px;
}

button {
  padding: 8px 15px;
  margin: 0 5px;
  border: none;
  border-radius: 4px;
  cursor: pointer;
  background: #007bff;
  color: white;
}

button:hover {
  background: #0056b3;
}

.edit-actions button {
  background: #28a745;
}

.edit-actions button:last-child {
  background: #dc3545;
}

.user-list table {
  width: 100%;
  border-collapse: collapse;
  margin-top: 20px;
}

.user-list th,
.user-list td {
  padding: 12px;
  border: 1px solid #ddd;
  text-align: left;
}

.user-list th {
  background-color: #f8f9fa;
}

.user-list tr:nth-child(even) {
  background-color: #f2f2f2;
}

input[type="email"] {
  width: 200px;
  padding: 5px;
}
</style>