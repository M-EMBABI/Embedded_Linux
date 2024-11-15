import tkinter as gui
import time
import RPi.GPIO as GPIO
import threading
led = 21
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led,GPIO.OUT) 

x=0
def led_toogel():
    global x
    x^=1
    GPIO.output(led,x)
    
main_win=gui.Tk()
main_win.title(" togel led ")

main_win.geometry("400x200+500+300")
main_win.configure(background="black")
button=gui.Button(main_win,text="led_togle",command=led_toogel,bg="red")
button.place(x=50,y=50)
main_win.mainloop()