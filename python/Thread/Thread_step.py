# 避免死锁示例：使用锁超时
import threading
import time

lock1 = threading.Lock()
lock2 = threading.Lock()

def task1():
    while True:
        if lock1.acquire(timeout=0.5):  # 设置超时
            try:
                print("任务1 获取锁1")
                time.sleep(0.1)
                if lock2.acquire(timeout=0.5):
                    try:
                        print("任务1 获取锁2")
                    finally:
                        lock2.release()
            finally:
                lock1.release()
            break

def task2():
    while True:
        if lock2.acquire(timeout=0.5):
            try:
                print("任务2 获取锁2")
                time.sleep(0.1)
                if lock1.acquire(timeout=0.5):
                    try:
                        print("任务2 获取锁1")
                    finally:
                        lock1.release()
            finally:
                lock2.release()
            break

t1 = threading.Thread(target=task1)
t2 = threading.Thread(target=task2)
t1.start()
t2.start()
t1.join()
t2.join()