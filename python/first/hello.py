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

""" str = input("请输入：");
print ("你输入的内容是: ", str)
 """

""" import os

current_directory = os.getcwd()
print("当前工作目录:", current_directory)

files_and_dirs = os.listdir()
print("目录内容:", files_and_dirs) """

""" class firstClass:
    a = 100
    def firstMethod(self):
        return "hello world!"
    
# 实例化类
first = firstClass()

# 访问类的属性和方法
print("类的属性a值为:", first.a)
print("类的方法firstMethod为:",first.firstMethod()) """

""" import re
print(re.match('www', 'www.runoob.com').span())

import re
result = re.match(r'Hello', 'Hello world')  # 匹配成功
print(result.group()) if result else print("No match") """


""" import re
 
line = "Cats are smarter than dogs"
# .* 表示任意匹配除换行符(\n、\r)之外的任何单个或多个字符
# (.*?) 表示"非贪婪"模式，只保存第一个匹配到的子串
matchObj = re.match( r'(.*) are (.*?) (.*) (.*)', line, re.M|re.I)
 
if matchObj:
   print ("matchObj.group() : ", matchObj.group())
   print ("matchObj.group(1) : ", matchObj.group(1))
   print ("matchObj.group(2) : ", matchObj.group(2))
   print ("matchObj.group(3) : ", matchObj.group(3))
   print ("matchObj.group(4) : ", matchObj.group(4))
else:
   print ("No match!!") """

""" import re
text = "Contact: email@example.com, phone: 123-4567"
match = re.search(r'(\w+@\w+\.\w+)', text)
if match:
    print("Found email:", match.group(1))  # 输出捕获的邮箱 """


""" import re
 
line = "Cats are smarter than dogs"
 
matchObj = re.match( r'dogs', line, re.M|re.I)
if matchObj:
   print ("match --> matchObj.group() : ", matchObj.group())
else:
   print ("No match!!")
 
matchObj = re.search( r'dogs', line, re.M|re.I)
if matchObj:
   print ("search --> matchObj.group() : ", matchObj.group())
else:
   print ("No match!!") """

""" import re

# 直接编译正则表达式
pattern = re.compile(r'([a-z]+) ([a-z]+)', re.I)  # 忽略大小写

# 执行匹配
m = pattern.match('Hello World Wide Web')

# 输出匹配结果
print("完整匹配对象:", m)
print("整个匹配内容:", m.group(0))
print("整个匹配位置:", m.span(0))
print("第一个分组内容:", m.group(1))
print("第一个分组位置:", m.span(1))
print("第二个分组内容:", m.group(2))
print("第二个分组位置:", m.span(2))
print("所有分组内容:", m.groups())

# 故意访问不存在的分组
print("尝试访问第三个分组:")
try:
    print(m.group(3))
except IndexError as e:
    print(f"出现错误: {e} (这是预期错误)") """


""" import re

# 直接编译正则表达式（匹配数字）
pattern = re.compile(r'\d+')

# 测试1：从字符串开头匹配（无数字开头）
m1 = pattern.match('one12twothree34four')
print("从头匹配结果:", m1)  # None

# 测试2：从索引2开始匹配（字符'e'位置）
m2 = pattern.match('one12twothree34four', 2, 10)
print("位置2-10匹配:", m2)  # None

# 测试3：从索引3开始匹配（字符'1'位置）
m3 = pattern.match('one12twothree34four', 3, 10)
print("位置3-10匹配:", m3)  # 返回Match对象

# 输出匹配详情
if m3:
    print("匹配内容:", m3.group())  # '12'
    print("起始位置:", m3.start())  # 3
    print("结束位置:", m3.end())    # 5
    print("位置范围:", m3.span())   # (3,5) """


