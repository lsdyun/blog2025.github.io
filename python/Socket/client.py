# 导入 socket 模块
import socket

# 创建 TCP Socket
clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 获取本地主机名
host = '127.0.0.1'  # 服务器地址socket.gethostname()

# 设置端口号
port = 9999

# 连接服务，指定主机和端口
clientsocket.connect((host, port))
print(f"已连接到服务器 {host}:{port}")

# 发送消息
try:
    while True:
        # 用户输入消息
        message = input("发送消息 (输入 'exit' 退出): ")
        if message.lower() == 'exit':
            break
        
        # 发送数据
        clientsocket.sendall(message.encode('utf-8'))
        
        # 接收服务器回复
        data = clientsocket.recv(1024)
        print(f"服务器回复: {data.decode('utf-8')}")
finally:
    clientsocket.close()
    print("连接已关闭")