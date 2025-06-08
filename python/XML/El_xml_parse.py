import xml.etree.ElementTree as ET

# 定义一个 XML 字符串
xml_string = '''
<bookstore>
    <book>
        <title>Python简介</title>
        <author>John Doe</author>
        <price>29.99</price>
    </book>
    <book>
        <title>Data Science with Python</title>
        <author>Jane Smith</author>
        <price>39.95</price>
    </book>
</bookstore>
'''

# 使用 ElementTree 解析 XML 字符串
root = ET.fromstring(xml_string)

# 遍历 XML 树
for book in root.findall('book'):
    title = book.find('title').text
    author = book.find('author').text
    price = book.find('price').text
    print(f'题目: {title}, 作者: {author}, 价格: {price}')