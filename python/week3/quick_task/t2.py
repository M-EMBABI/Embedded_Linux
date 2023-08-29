from tkinter import *


def reverse():

    z=e1.get()
    z=z[::-1]
    print(z)
    result_label.config(text= z) 

    

window=Tk()
window.title("GUI")
window.geometry("500x500+150+200")


lbl1=Label(window,text="First name").grid(row=0)
lbl2=Label(window,text=" text reversed ").grid(row=4,column=1)

result_label = Label(window,bg="black",fg="white", text="      ")
result_label.grid(row=5,column=1)


e1=Entry(window)
e1.grid(row=0,column=1)

button=Button(window,text="reverse",command=reverse).grid(row=2)


window.mainloop()
