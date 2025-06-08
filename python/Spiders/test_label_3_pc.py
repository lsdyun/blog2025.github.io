from bs4 import BeautifulSoup
import requests
# 使用 chardet 自动检测编码
import chardet

# 指定你想要获取标题的网站
url = 'https://www.baidu.com/' # 抓取bing搜索引擎的网页内容

# 发送HTTP请求获取网页内容
response = requests.get(url)

# 解决中文乱码问题
encoding = chardet.detect(response.content)['encoding']
print("编码为：",encoding)
response.encoding = encoding 

# 省略获取url、编码
if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'lxml')

    # 查找第一个 <a> 标签
    first_link = soup.find('a')
    print(first_link)
    print("----------------------------")

    # 获取当前标签的父标签
    parent_tag = first_link.parent
    print(parent_tag.get_text())
    
else:
    print("请求失败，状态码：", response.status_code)