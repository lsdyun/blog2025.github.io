import smtplib			#用于SMTP协议通信
from email.mime.text import MIMEText		#创建邮件正文
from email.header import Header			#处理邮件头信息
from email.utils import formataddr

# 第三方 SMTP 服务
mail_host="smtp.163.com"  #设置服务器
mail_port = 465  # SSL端口
mail_user="l2307526822@163.com"    #用户名
mail_pass="HNR4v36SNB5kabyq"   #口令 

sender = mail_user	#发件人(sender)邮箱地址
receivers = ['2307526822@qq.com']  # 收件人(receivers)邮箱地址
 
# 邮件正文
# 文本内容, 文本格式, 编码
message = MIMEText('Python 邮件发送测试...', 'plain', 'utf-8')	

# 设置From(发件人显示名)和To(收件人显示名)头信息
""" message['From'] =  mail_user #Header(f"发送者 <{mail_user}>", 'utf-8')     
message['To'] =  Header("接收者 <2307526822@qq.com>", 'utf-8')  """ 
# 自动处理编码        
message['From'] = formataddr(("发送者2", mail_user))   # 发送者
message['To'] = formataddr(("接收者2", receivers[0]))    # 接收者
message['Subject'] = 'Python SMTP 邮件测试'  # 主题可以直接用字符串
 
 
try:
    # 创建SMTP对象连接到第三方服务器
    smtpObj = smtplib.SMTP_SSL(mail_host, mail_port)
    smtpObj.login(mail_user,mail_pass)
    # 调用sendmail()方法发送邮件
    smtpObj.sendmail(sender, receivers, message.as_string())
    print ("邮件发送成功")
except Exception as e:
    print(f"发送失败: {str(e)}")
finally:
    smtpObj.quit()