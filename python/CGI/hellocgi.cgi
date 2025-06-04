# D:/blog/code/blog2025.github.io/python/CGI/hello.cgi
print("Content-type: text/html\n")
print()                             # 空行，告诉服务器结束头部
print("<html>")
print('<head>')
print('<meta charset="utf-8">')
print("<title>我的第一个Windows CGI程序</title>")
print('</head>')
print('<body>')
print("<h2>Hello World! Windows CGI测试</h2>")
print('</body>')
print('</html>')