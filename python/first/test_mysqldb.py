import mysql.connector
 
mydb = mysql.connector.connect(
  host="localhost",       # 数据库主机地址
  user="root",    # 数据库用户名
  passwd="root",   # 数据库密码
  database="python_db"    #数据库名
)
 
# print(mydb.database)

mycursor = mydb.cursor()

''' 创建database数据库python_db
mycursor.execute("CREATE DATABASE python_db")
'''

'''输出所有数据库名
mycursor.execute("SHOW DATABASES")
 
for x in mycursor:
  print(x)
'''
# mycursor.execute("CREATE TABLE sites (name VARCHAR(255), url VARCHAR(255))")

#mycursor.execute("ALTER TABLE sites ADD COLUMN id INT AUTO_INCREMENT PRIMARY KEY")

""" sql = "INSERT INTO sites (name, url) VALUES (%s, %s)"
val = ("RUNOOB", "https://www.runoob.com")  #python元组

mycursor.execute(sql, val)

mydb.commit()    # 数据表内容有更新，必须使用到该语句
 
print(mycursor.rowcount, "记录插入成功。") """

""" sql = "INSERT INTO sites (name, url) VALUES (%s, %s)"
val = [
  ('Google', 'https://www.google.com'),
  ('Github', 'https://www.github.com'),
  ('Taobao', 'https://www.taobao.com'),
  ('stackoverflow', 'https://www.stackoverflow.com/')
]
 
mycursor.executemany(sql, val)
 
mydb.commit()    # 数据表内容有更新，必须使用到该语句
 
print(mycursor.rowcount, "记录插入成功。") """

""" mycursor.execute("SELECT * FROM sites")
 
myresult = mycursor.fetchall()     # fetchall() 获取所有记录
 
for x in myresult:
  print(x) """

""" mycursor = mydb.cursor()
 
mycursor.execute("SELECT * FROM sites")
 
myresult = mycursor.fetchone()
 
print(myresult) """

""" mycursor = mydb.cursor()
 
sql = "DELETE FROM sites WHERE name = 'stackoverflow'"
 
mycursor.execute(sql)
 
mydb.commit()
 
print(mycursor.rowcount, " 条记录删除") """


""" mycursor = mydb.cursor()
 
sql = "UPDATE sites SET name = 'ZH' WHERE name = 'Zhihu'"
 
mycursor.execute(sql)
 
mydb.commit()
 
print(mycursor.rowcount, " 条记录被修改") """
