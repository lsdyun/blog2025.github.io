from bs4 import BeautifulSoup
import requests
# 使用 chardet 自动检测编码
import chardet

# 指定你想要获取标题的网站
url = 'https://cn.bing.com' # 抓取bing搜索引擎的网页内容

# 发送HTTP请求获取网页内容
response = requests.get(url)

# 解决中文乱码问题
encoding = chardet.detect(response.content)['encoding']
print("编码为：",encoding)
response.encoding = encoding 

# 获取url、编码
if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'lxml')

    # 获取第一个 <title> 标签中的文本内容
    paragraph_text = soup.find('title').get_text()
    # 打印标题文本
    print("标题：",paragraph_text)
    print("-" * 30)

    # 获取页面中所有文本内容
    all_text = soup.get_text()
    print("页面所有文本：",all_text)

    # 查找<title>标签
    title_tag = soup.find('title')
    
else:
    print("请求失败，状态码：", response.status_code)