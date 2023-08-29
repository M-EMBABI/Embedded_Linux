from tkinter import *
import tkinter as tk
def led_on():
    print("led on")

window=tk.Tk()
# b=tk.Tk()
window.title("GUI")

window.geometry("500x500+150+200")


button1=tk.Button(window,text="led on ",width=10,command=led_on,fg="white",bg="black").place(x=200,y=0)
button2=tk.Button(window,text="led on ",width=10,command=led_on,fg="white",bg="black").place(x=200,y=60)
button3=tk.Button(window,text="led on ",width=10,command=led_on,fg="white",bg="black").place(x=300,y=30)
button4=tk.Button(window,text="led on ",width=10,command=led_on,fg="white",bg="black").place(x=100,y=30)

window.mainloop()
