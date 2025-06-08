import json

# 从test.json文件中读取JSON数据
with open('JSON/test.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

# 解析JSON数据
for site in data['sites']:
    print(f"网站名称: {site['name']}")
    print(f"网站地址: {site['url']}")
    print("-" * 30)
 
