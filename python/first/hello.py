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

a = {1, 2, 3, 4, "haha"}
a.clear()
print(a)
