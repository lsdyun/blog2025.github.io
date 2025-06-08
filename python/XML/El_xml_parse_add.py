import xml.etree.ElementTree as ET

# 创建一个XML文档
root = ET.Element('bookstore')

# 添加第一本书
book1 = ET.SubElement(root, 'book')
title1 = ET.SubElement(book1, 'title')
title1.text = 'Introduction to Python'
author1 = ET.SubElement(book1, 'author')
author1.text = 'John Doe'
price1 = ET.SubElement(book1, 'price')
price1.text = '29.99'

# 添加第二本书
book2 = ET.SubElement(root, 'book')
title2 = ET.SubElement(book2, 'title')
title2.text = 'Data Science with Python'
author2 = ET.SubElement(book2, 'author')
author2.text = 'Jane Smith'
price2 = ET.SubElement(book2, 'price')
price2.text = '39.95'

# 将XML文档保存到文件
tree = ET.ElementTree(root)
tree.write('XML/books.xml')

# 从文件中解析XML文档
parsed_tree = ET.parse('XML/books.xml')
parsed_root = parsed_tree.getroot()

# 遍历XML树并打印书籍信息
for book in parsed_root.findall('book'):
    title = book.find('title').text
    author = book.find('author').text
    price = book.find('price').text
    print(f'Title: {title}, Author: {author}, Price: {price}')