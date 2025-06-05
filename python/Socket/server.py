# 导入 socket 模块
import socket

# 创建 socket 对象
serversocket = socket.socket(
            socket.AF_INET, socket.SOCK_STREAM)

# 获取本地主机名
host = '127.0.0.1'  # 本地回环地址 #socket.gethostname()

port = 9999

# 绑定端口号
serversocket.bind((host, port))


# 开始监听（最多允许5个等待连接）
serversocket.listen(5)
print(f"服务器启动，监听 {host}:{port}...")


# 接受客户端连接
clientsocket,addr = serversocket.accept()    
print(f"客户端 {addr} 已连接")  

# 与客户端通信
try:
    while True:
        # 接收数据（最多1024字节）
        data = clientsocket.recv(1024)
        if not data:
            break  # 客户端断开连接
        
        message = data.decode('utf-8')
        print(f"收到消息: {message}")
        
        # 回复确认
        response = f"已收到: {message}"
        clientsocket.sendall(response.encode('utf-8'))
finally:
    # 关闭连接
    clientsocket.close()
    serversocket.close()
    print("服务器已关闭")