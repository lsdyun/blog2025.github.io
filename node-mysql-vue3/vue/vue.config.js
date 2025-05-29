const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true
})

module.exports = {
  devServer: {
    proxy: {
      // 开发环境代理配置
      '/api': {
        /* 
        如果 process.env.VUE_APP_API_BASE_URL 存在且为真值（truthy value），则使用该值 
        如果环境变量未定义（undefined）、空字符串（''）、null 或其他假值（falsy），则使用 'http://localhost:3001'
        */
        target: process.env.VUE_APP_API_BASE_URL || 'http://localhost:3001',
        changeOrigin: true,
        /* pathRewrite: {
          '^/api': '' // 移除路径中的 /api 前缀
        } */
      }
    }
  }
}