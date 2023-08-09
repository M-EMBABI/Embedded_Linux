
import tkinter as tk
from PIL import ImageTk, Image
import requests

def TAKE_string():
    input_string = entry.get()
    if input_string =="linux" :
 
      image_label.config(image=image)
    elif input_string == "bitcoin":
      
        url= requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
        
      
        
        image_label.config(text= url.json()['bpi']['USD']) 
    else:
      pass
      print("data not correct please enter linux OR bitcoin")     

# Create the main window 
im =  url= requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
window = tk.Tk()
window.title(" embabi test GUI ")

# Load and resize the image
image_path = "/home/embabi/Downloads/images.png"
image = Image.open(image_path)
image = image.resize((300, 300), Image.ANTIALIAS)
image = ImageTk.PhotoImage(image)
################################################################

################################################################
# Create the input entry field
entry = tk.Entry(window, width=30)
entry.pack()

# Create the open button
OPEN_button = tk.Button(window, text="open", command=TAKE_string)
OPEN_button.pack()

# Create the label to display the result
result_label = tk.Label(window, text="")
result_label.pack()

# Create the label to display the image
image_label = tk.Label(window, image=None)
image_label.pack()

# Start the GUI event loop
window.mainloop()