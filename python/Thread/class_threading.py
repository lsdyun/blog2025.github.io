import threading
import time

# 自定义线程类，继承 threading.Thread
class PrintTimeThread(threading.Thread):
    def __init__(self, threadName, delay):
        # 调用父类构造函数
        super().__init__()
        # 初始化实例变量
        self.threadName = threadName
        self.delay = delay
    
    # 重写 run() 方法 - 线程启动后执行的实际任务
    def run(self):
        print(f"线程 {self.threadName} 启动")
        count = 0
        while count < 5:
            time.sleep(self.delay)  # 按指定延迟暂停
            count += 1
            # 打印线程名和当前格式化时间
            print(f"{self.threadName}: {time.ctime(time.time())}")
        print(f"线程 {self.threadName} 结束")

# 创建线程实例
thread1 = PrintTimeThread("Thread-1", 2)
thread2 = PrintTimeThread("Thread-2", 4)

# 启动线程
thread1.start()
thread2.start()

# 主线程等待子线程完成
thread1.join()
thread2.join()

print("所有线程执行完毕")