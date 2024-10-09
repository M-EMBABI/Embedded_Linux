import smtplib
from email.mime.text import MIMEText
import subprocess

def get_uptime():
    # Get the system uptime
    uptime = subprocess.check_output("uptime", shell=True).decode('utf-8')
    return uptime

def send_email(uptime_report):
    # Email details
    sender = "your-email@gmail.com"
    recipient = "friend-email@gmail.com"
    subject = "Uptime Report"
    body = f"Hi,\n\nHere is the system uptime report:\n\n{uptime_report}"

    # Create the email message
    msg = MIMEText(body)
    msg['Subject'] = subject
    msg['From'] = sender
    msg['To'] = recipient

    # Gmail SMTP server details
    smtp_server = "smtp.gmail.com"
    smtp_port = 587
    password = "your-email-password"  # Use an app password for better security

    # Send the email
    with smtplib.SMTP(smtp_server, smtp_port) as server:
        server.starttls()  # Secure the connection
        server.login(sender, password)
        server.sendmail(sender, recipient, msg.as_string())
        print("Email sent successfully!")

if __name__ == "__main__":
    uptime_report = get_uptime()
    send_email(uptime_report)
