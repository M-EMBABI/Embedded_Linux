import tkinter
from tkinter import *

def led_on():
    print(5+6)
        
    window = tkinter.Tk()
    window.title("led control")
    window.geometry("500x500+150+200")
    C = tkinter.Canvas(window, bg="light gray", height=150, width=150,scrollregion=(40,30,30,30))

    coord = 50, 50, 150, 150
    # arc = C.create_arc(coord, start=0, extent=150, fill="red")
    C.create_oval(coord,fill="white",offset=["center"])
    C.place(x=180,y=50)
    window.mainloop()

def led_off():
        
    window = tkinter.Tk()
    window.title("led control")
    window.geometry("500x500+150+200")
    C2= tkinter.Canvas(window, bg="light gray", height=150, width=150,scrollregion=(40,30,30,30))

    coord = 50, 50, 150, 150
    C2.create_oval(coord,fill="red",offset=["center"])
    C2.place(x=180,y=50)
    window.mainloop()
    
    
window = tkinter.Tk()
window.title("led control")
window.geometry("500x500+150+200")
# C = tkinter.Canvas(window, bg="light gray", height=150, width=150,scrollregion=(40,30,30,30))
# C1 = tkinter.Canvas(window, bg="light blue", height=150, width=150,scrollregion=(40,30,30,30))

# coord = 50, 50, 150, 150
# # arc = C.create_arc(coord, start=0, extent=150, fill="red")
# oval = C.create_oval(coord,fill="white",offset=["center"])
v=IntVar()
v2=IntVar()

v=1
v2=2

button=Button(window,text="led on",textvariable=v,command=led_on)
button2=Button(window,text="led off",textvariable=v2,command=led_off)

b=button.place(x=220,y=200)
b2=button2.place(x=220,y=240)







window.mainloop()