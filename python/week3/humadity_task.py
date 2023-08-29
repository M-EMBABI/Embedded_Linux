from tkinter import *
import random
 
def update_gauge():
    newvalue = random.randint(low_r,hi_r)
    cnvs.itemconfig(id_text,text = str(newvalue) + " %")
    
   
    angle = 120 * (hi_r - newvalue)/(hi_r - low_r) + 30
    cnvs.itemconfig(needle,start = angle)
    window.after(3000, update_gauge)
 
     
  
 
canvas_width = 400
canvas_height =300
 
window = Tk()
 
cnvs = Canvas(window, width=canvas_width, height=canvas_height)
cnvs.grid(row=2, column=1)
 
coord = 10, 50, 350, 350 #define the size of the gauge
low_r = 0 # chart low range
hi_r = 120 # chart hi range
 
# Create a background arc with a number of range lines
numpies = 10
for i in range(numpies):
    cnvs.create_arc(coord, start=(i*(120/numpies) +30), extent=(120/numpies),
                    fill="white",  width=0)    
 

cnvs.create_arc(coord, start=30, extent=120, outline="green", style= "arc", width=30)
cnvs.create_arc(coord, start=30, extent=13, outline="red", style= "arc", width=30)
cnvs.create_arc(coord, start=43, extent=35, outline="yellow", style= "arc", width=30)


needle = cnvs.create_arc(coord, start= 119, extent=0, width=3)
 

cnvs.create_text(180,15,font="Times 20 bold", text="Humidity")
cnvs.create_text(25,140,font="Times 12 bold", text=low_r)
cnvs.create_text(330,140,font="Times 12 bold", text=hi_r)
id_text = cnvs.create_text(170,210,font="Times 15 bold")
 
window.after(300, update_gauge)
 
window.mainloop()