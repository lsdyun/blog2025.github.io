""" print("hello world!")
print("你好，世界！") """

""" 
str = 'helloworld'
print(str[2:5])
print(str[0:-1]) 
print(str[1:5:2])
print("this is a line with \n yourname")
print(r"this is a line with \n yourname") 
"""

#input("\n\n按下 enter 键后退出。")
#import sys; x = 'hello'; sys.stdout.write(x + '\n')
""" 
print("hello", end="")
print("world!") 
"""

""" 
a = 10
b = "hello"
print(type(a))

print(type(b)) 
"""

""" 
a = 100
print(isinstance(a, int)) 
"""

""" 
print(2 / 4)
print(2 // 4)
 """

""" a = 10
b = -90.
print(a + b) """

""" str = 'helloworld'
print(str * 2) """

""" str = 'helloworld'
str[0] = 'g'
print(str) """

""" a = ['a','b']
b = ['c','d','e']
print(a + b)
# 输出 ['a','b','c','d','e']
print(a * 2)
# 输出 ['a','b','a','b'] """

""" list = ['a','b','c','d','e']
print(list[1:3])
print(list[1:4:2]) """

""" a = ['a','b','']
a[2] = 'c'
print(a) """

""" lst = [3, 1, 4]
lst.reverse()
print(lst) """

""" tuple = ('a', 10, 33, 'hello',3,5,1)
print(tuple)
print(tuple[1:3])
print(tuple * 2) 
print(tuple[1:6:2]) """

""" tuple = ('a', 10)
tuple[0] = 1
print(tuple)
 """

""" tupleA = ('a')
print(type(tupleA))
tupleB = ('a',)
print(type(tupleB)) """

""" a = {'value1', 'value2', 'value3', '...'}
set(a)
print(a) """

""" a = {1, 2, 3, 4, 2, 2}
print(a) """

""" a = {1, 2, 3, 4, 2, 2}
b = {'value1', 'value2', 3}
print(a - b)
print(a | b)
print(a & b)
print(a ^ b) """


""" dictionary = {}
dictionary[1] = "hello"
print(dictionary[1]) """

""" dicA = {"firstname": "zhang", "lastname": "san", "class": 1}
print(dicA.keys())
print(dicA.values()) """

""" A = dict([('apple','red'), ('book',10), ('name', '张三')])
print(A) """

""" B = dict(apple='red', book=10, name='张三')
print(B) """

""" A = [('apple','red'), ('book',10), ('name', '张三')]
print(dict(A)) """

""" B = {'apple': 'red', 'book': 10, 'name': '张三'}
print(B) """

""" x = b"hello"
print(type(x)) """

""" name = '张三'
print('Hello %s' % name) """

""" name = '张三'
print(f'Hello {name}') """

""" print(f'{1+1}') """

""" a = {'name': '张三','word': '你好'}
b = f'{a["name"]}: {a["word"]}'
print(b) """

""" lst = [1, 'a', 2, 3, 4, 5]
del lst[1]
print(lst) """

""" a = ['a', 'b', 'c']
n = [1, 2, 3]
x = [a, n]
print(x)
print(x[0])
print(x[0][1])
print(x[1][1]) """

""" import operator

a = [1, 2]
b = [2, 3]
c = [2, 3]
print("a和b是否相同: ", operator.eq(a,b))
print("c和b是否相同: ", operator.eq(c,b)) """

"""
tuple = ('a', 10, 33, 'hello')

del tuple[3]
print(tuple) 
del tuple
print(tuple)"""

""" list1= ['a','b','c','d','e']
tuple1=tuple(list1)
print(tuple1) """

""" dicA = {"firstname": "zhang", "lastname": "san", "class": 1}

print(dicA['firstname'])
print(dicA['class'])
dicA["class"] = 10
dicA["firstname"] = '张'
print(dicA) """

""" dicA = {"firstname": "zhang", "lastname": "san", "class": 1}
del dicA['lastname']
dicA.clear()
del dicA
print(dicA) """

""" a = {1, 2, 3, 4, 2, 2}
a.add(10)
print(a) """

""" a = {1, 2, 3, 4, 2, 2}
a.update(["列表","100"]) # 元组
a.update({111,333}) # 集合
a.update({"firstname": "张", "lastname": "三"})
a.update((100,222))
print(a)  """

""" a = {1, 2, 3, 4, "haha"}
a.remove("haha")
a.remove('aaa')
print(a) """

""" a = {1, 2, 3, 4, "haha"}
a.discard('aaa')
print(a) """

""" a = {1, 2, 3, 4, "haha"}
a.pop()
print(a) """

""" a = {1, 2, 3, 4, "haha"}
a.clear()
print(a) """

""" def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "Not found"
        case 418:
            return "I'm a teapot"
        case _:
            return "Something's wrong with the internet"

mystatus=400
print(http_error(400)) """

""" n = 100
 
sum = 0
counter = 1
while counter <= n:
    sum = sum + counter
    counter += 1
 
print("1 到 %d 之和为: %d" % (n,sum)) """

""" var = 1
while var == 1 :  # 表达式永远为 true
   num = int(input("输入一个数字  :"))
   print ("你输入的数字是: ", num)
 
print ("Good bye!") """

""" sites = ["Baidu", "Google","Runoob","Taobao"]
for site in sites:
    print(site) """

""" word = 'helloworld'
 
for letter in word:
    print(letter) """

#!/usr/bin/python3
 
""" sites = ["Baidu", "Google","Runoob","Taobao"]
for site in sites:
    
    if site == "Runoob":
        print("菜鸟教程!")
        break
    print("循环数据 " + site)
else:
    print("没有循环数据!")
print("完成循环!") """

""" a = list(range(1,5))
print(a) """

""" words = ['hello', 'world', 'python']
unique_chars = {ch for word in words for ch in word} 
print(unique_chars) """

""" gen = (x*2 for x in range(5)) 
print(tuple(gen)) """

""" list=[1,2,3,4]
it = iter(list)
print(next(it))
print(next(it))
for x in it:
    print(x,end=" ") """

""" import sys         # 引入 sys 模块

list=[1,2,3,4]
it = iter(list)	# 创建迭代器对象
while True:
    try:
        print(next(it))
    except StopIteration:
        sys.exit() """

""" class NumberIterator:
    def __init__(self, max_num):
        self.max = max_num
        self.current = 0

    def __iter__(self):
        return self  # 返回迭代器对象本身

    def __next__(self):
        if self.current < self.max:
            self.current += 1
            return self.current
        raise StopIteration  # 终止迭代
    
myclass = NumberIterator(5)
myiter = iter(myclass)
 
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter)) """


""" class NumberIterator:
    def __init__(self, max_num):
        self.max = max_num
        self.current = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.current >= self.max:
            raise StopIteration
        self.current += 1
        return self.current

# 直接使用类实例作为迭代器（无需显式调用iter()）
nums = NumberIterator(5)
for num in nums:
    print(num) """


""" def change(a):
    print("a2的内存位置:",id(a),"|a2的值为:",a)
    
a = 1
print("a1的内存位置:",id(a),"|a1的值为:",a)

a = 2
change(a) """

""" def change(list):
    print("列表2内存地址为:",id(list),"列表2的内容为:",list)


list=[1,2,3,4]
print("列表1内存地址为:",id(list),"列表1的内容为:",list)

list.append([5,6,7,8])
change(list)
 """


""" 
import time

def timing_decorator(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"函数 {func.__name__} 执行耗时: {end_time - start_time:.4f}秒")
        return result
    return wrapper

@timing_decorator
def calculate_sum(n):
    return sum(range(n+1))

# 测试
print(calculate_sum(1000000))
 """
""" import sys

if __name__ == '__main__':
   print('程序自身在运行')
else:
   print('我来自另一模块') """

""" a = "hello world"
print(str(a))
print(repr(a)) """

""" import math
print('常量 PI 的值近似为： {}。'.format(math.pi))
# 常量 PI 的值近似为： 3.141592653589793。
print('常量 PI 的值近似为： {!s}。'.format(math.pi))
# 常量 PI 的值近似为： 3.141592653589793。 """

str = input("请输入：");
print ("你输入的内容是: ", str)
