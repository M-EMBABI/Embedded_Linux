import tkinter as tk
from math import factorial

def c_factorial():
    
    n = int(entry.get())
    result = factorial(n)
    result_lbl.config(text=f"The factorial of {n} is: {result}")


window = tk.Tk()
window.title("Factorial")
window.geometry("200x200")


label = tk.Label(window, text="Enter num:")
label.pack()

entry = tk.Entry(window)
entry.pack()

button = tk.Button(window, text="Calculate", command=c_factorial)
button.pack()

result_lbl = tk.Label(window, text="")
result_lbl.pack()

window.mainloop()