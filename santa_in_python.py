import sys
# Import smtplib for the actual sending function
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

me = sys.argv[1]#"lopezbryanrr@gmail.com"
my_password = sys.argv[2]#r"migatoeraroscoe117!"
you = "bryanlopezrr@gmail.com"

msg = MIMEMultipart('alternative')
msg['Subject'] = "Alert"
msg['From'] = me
msg['To'] = you

html = '<html><body><h1>Cuchumbo 2020!</h1><h2>Esta es la persona que le tienes que dar regalo:</h2></body></html>'
part2 = MIMEText(html, 'html')

msg.attach(part2)
s = smtplib.SMTP_SSL('smtp.gmail.com')
s.login(me, my_password)

s.sendmail(me, you, msg.as_string())

print (s)

s.quit()

