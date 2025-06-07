import smtplib
import os
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.application import MIMEApplication
from email.utils import formataddr

# ======================= 配置区 =======================
SMTP_SERVER = "smtp.163.com"
SMTP_PORT = 465
EMAIL_USER = "l2307526822@163.com"
EMAIL_PASSWORD = "HNR4v36SNB5kabyq"  # 使用授权码而非登录密码

RECEIVERS = ["2307526822@qq.com"]
SUBJECT = "带附件和图片的HTML邮件测试"

# 图片和附件配置
IMAGE_FILE = "SMTP/email_image.png"  # 确保此文件存在
ATTACHMENT_FILE = "SMTP/sample_document.pdf"  # 确保此文件存在
# =====================================================

def send_email():
    """发送带附件和图片的HTML邮件"""
    # 创建邮件主体
    msg = MIMEMultipart()
    msg["Subject"] = SUBJECT
    msg["From"] = formataddr(("Python邮件系统", EMAIL_USER))
    msg["To"] = ", ".join(RECEIVERS)
    
    # 创建HTML内容（包含图片占位符）
    html_content = f"""
    <html>
    <body style="font-family: Arial, sans-serif; max-width: 600px; margin: auto;">
        <div style="background: #f8f9fa; padding: 20px; border-radius: 10px;">
            <h1 style="color: #2c3e50;">带图片和附件的HTML邮件</h1>
            
            <p>这是一封使用Python发送的测试邮件，包含以下内容：</p>
            <ul>
                <li>HTML格式的正文</li>
                <li>内嵌图片展示</li>
                <li>文件附件</li>
            </ul>
            
            <div style="text-align: center; margin: 20px 0;">
                <h3>内嵌图片示例：</h3>
                <!-- 图片通过CID嵌入 -->
                <img src="cid:email_image" alt="示例图片" style="max-width: 90%; border: 1px solid #ddd; padding: 5px;">
                <p><em>图片已嵌入邮件中，无需单独下载</em></p>
            </div>
            
            <p>邮件中还包含了一个PDF文件作为附件，请查收。</p>
            
            <div style="margin-top: 30px; padding-top: 15px; border-top: 1px solid #eee; color: #777;">
                <p>发送时间: 2025-06-07</p>
                <p>发件人: Python邮件系统 &lt;{EMAIL_USER}&gt;</p>
                <p>收件人: {", ".join(RECEIVERS)}</p>
            </div>
        </div>
    </body>
    </html>
    """
    
    # 添加HTML内容
    msg.attach(MIMEText(html_content, "html", "utf-8"))
    
    # 添加内嵌图片
    if os.path.exists(IMAGE_FILE):
        with open(IMAGE_FILE, "rb") as img_file:
            img = MIMEImage(img_file.read(), name=os.path.basename(IMAGE_FILE))
            img.add_header("Content-ID", "<email_image>")  # 匹配HTML中的cid
            msg.attach(img)
    else:
        print(f"警告: 图片文件 {IMAGE_FILE} 不存在，邮件中图片将无法显示")
    
    # 添加附件
    if os.path.exists(ATTACHMENT_FILE):
        with open(ATTACHMENT_FILE, "rb") as attachment:
            part = MIMEApplication(attachment.read(), Name=os.path.basename(ATTACHMENT_FILE))
            part["Content-Disposition"] = f'attachment; filename="{os.path.basename(ATTACHMENT_FILE)}"'
            msg.attach(part)
    else:
        print(f"警告: 附件文件 {ATTACHMENT_FILE} 不存在")
    
    # 发送邮件
    try:
        with smtplib.SMTP_SSL(SMTP_SERVER, SMTP_PORT) as server:
            server.login(EMAIL_USER, EMAIL_PASSWORD)
            server.sendmail(EMAIL_USER, RECEIVERS, msg.as_string())
        print("邮件发送成功！请检查收件箱（包括垃圾邮件文件夹）")
        return True
    except Exception as e:
        print(f"邮件发送失败: {str(e)}")
        return False

if __name__ == "__main__":
    # 检查必要文件
    if not os.path.exists(IMAGE_FILE):
        print(f"提示: 请创建图片文件 {IMAGE_FILE} 或在代码中修改路径")
    if not os.path.exists(ATTACHMENT_FILE):
        print(f"提示: 请创建附件文件 {ATTACHMENT_FILE} 或在代码中修改路径")
    
    # 发送邮件
    send_email()