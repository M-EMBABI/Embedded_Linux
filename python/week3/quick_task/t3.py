from tkinter import *
from tkinter import messagebox

def calculator():
    num1=int(enter.get())
    num2=int(enter1.get())
    sum=num1+num2
    if v.get() == 1:
        sup=num1-num2
        messagebox.showinfo("sup = ",f"sup:{sup}\n")
        #with config
        # result_label.config(text= sup)
    else:
        messagebox.showinfo("sum = ",f"sum:{sum}\n")
        #with config
        # result_label.config(text= sum)   


#creat the main window
window=Tk()
window.title("calculator")
window.geometry("250x150+150+200")

#creat the input field
lbl=Label(window,text="first num")
lbl1=Label(window,text="second num")

enter=Entry(window)
enter1=Entry(window)

v=IntVar()
r=Radiobutton(window,text="sum",variable=v,value=0)
r1=Radiobutton(window,text="sup",variable=v,value=1)

l=lbl.grid(row=0)
l1=lbl1.grid(row=1)

e=enter.grid(row=0,column=1)
e1=enter1.grid(row=1,column=1)

r.grid(row=2)
r1.grid(row=3)

calculator=Button(window,text="calculator",command=calculator)
calculator.grid(row=2,column=1)

result_label = Label(window, text="      ")
result_label.grid(row=5,column=1)

window.mainloop()
