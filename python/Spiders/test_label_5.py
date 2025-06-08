from bs4 import BeautifulSoup
import requests
# 使用 chardet 自动检测编码
import chardet

# 指定你想要获取标题的网站
url = 'https://cn.bing.com/' # 抓取bing搜索引擎的网页内容

# 使用完整浏览器头部
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36',
    'Accept-Language': 'zh-CN,zh;q=0.9'
}

# 发送HTTP请求获取网页内容
response = requests.get(url,headers=headers)

# 解决中文乱码问题
encoding = chardet.detect(response.content)['encoding']
print("编码为：",encoding)
response.encoding = encoding 

if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'lxml')
    
    # 方法1：直接从input标签提取data-ghosturl中的编码文本
    input_element = soup.find('input', id='sb_form_q')
    if input_element and 'data-ghosturl' in input_element.attrs:
        ghost_url = input_element['data-ghosturl']
        # 提取URL中的q参数值 (URL解码)
        from urllib.parse import unquote, parse_qs
        query = parse_qs(ghost_url.split('?')[1]).get('q', [''])[0]
        placeholder = unquote(query)
        print("方法1获取的占位文本:", placeholder)
    
    # 方法2：查找包含"今日热点"的列表项
    hot_items = soup.select('.sa_tm_text')
    if hot_items:
        print("方法2获取的今日热点:")
        for i, item in enumerate(hot_items[:5], 1):
            print(f"{i}. {item.get_text()}")
else:
    print("请求失败，状态码：", response.status_code)