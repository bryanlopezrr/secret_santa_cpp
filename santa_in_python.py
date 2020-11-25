import sys
import json
import os
import imghdr
# Import smtplib for the actual sending function
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

myfile = open("assignments.txt", "r")
text = myfile.readlines()

d = {}

for line in text:
    line = line.strip().split('-')
    sendee = line[0].strip()
    givee = line[1].strip()

    if sendee in d:
        d[sendee].append(givee)
    else:
        d[sendee] = [givee]

me = sys.argv[1]    
my_password = sys.argv[2]  

for key, value in d.items():
    you = str(key)
    assignee_email = str(value)[2:-2]

    msg = MIMEMultipart('alternative')
    msg['Subject'] = "Santa Secreto 2020!"
    msg['From'] = "Santa Claus"
    msg['To'] = you
    html = '<html><body><h1>Santa Secreto 2020!</h1><h2>Esta es la persona a la que le tienes que dar regalo:</h2><h3>'+ assignee_email + '</h3> <h2>Recuerden que los regalos deben estar dentro de el limite de $50. El intercambio se va a llevar acabo el dia 24 de Diciembre en Noche Buena. Los nin@s estan excluidos ya que ellos no pueden comprar los regalos. </h2></body></html>'
    part2 = MIMEText(html, 'html')

    #Attempting to add photo
    # foto = open('santa_img.jpeg', 'rb')
    # image_data = foto.read()
    # image_type = imghdr.what(foto.name)
    # image_name = foto.name
    
    # msg.add_attachment(image_data, maintype='image', subtype=image_type, filename=image_name)

    msg.attach(part2)
    s = smtplib.SMTP_SSL('smtp.gmail.com')
    s.login(me, my_password)

    s.sendmail(me, you, msg.as_string())

# print (s)

#Delete the text file so that I dont look at the assignments 
if os.path.exists("assignments.txt"):
    os.remove("assignments.txt")
else:
    print("El documento no existe")



s.quit()

