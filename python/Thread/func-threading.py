import threading
import time

def print_time(thread_name, delay):
    """线程执行函数"""
    count = 0
    while count < 5:
        time.sleep(delay)
        count += 1
        print(f"{thread_name}: {time.ctime(time.time())}")

if __name__ == "__main__":
    # 创建线程对象
    t1 = threading.Thread(target=print_time, args=("Thread-1", 2))
    t2 = threading.Thread(target=print_time, args=("Thread-2", 4))
    
    # 启动线程
    t1.start()
    t2.start()
    
    # 等待线程结束
    t1.join()
    t2.join()
    
    print("所有线程执行完毕")