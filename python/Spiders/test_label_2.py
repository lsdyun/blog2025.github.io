from bs4 import BeautifulSoup
import requests
# 使用 chardet 自动检测编码
import chardet

# 指定你想要获取标题的网站
url = 'https://cn.bing.com/' # 抓取bing搜索引擎的网页内容

# 发送HTTP请求获取网页内容
response = requests.get(url)

# 解决中文乱码问题
encoding = chardet.detect(response.content)['encoding']
print("编码为：",encoding)
response.encoding = encoding 

if response.status_code == 200:
    # 使用BeautifulSoup解析网页内容
    soup = BeautifulSoup(response.text, 'lxml')
    # 查找第一个 <a> 标签
    first_link = soup.find('a')
    print(first_link)
    print("----------------------------")

    # 获取第一个 <a> 标签的 href 属性
    first_link_url = first_link.get('href')
    print(first_link_url)
    print("----------------------------")

    # 查找所有 <a> 标签
    all_links = soup.find_all('a')
    print(all_links)
else:
    print("请求失败，状态码：", response.status_code)