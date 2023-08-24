import pyautogui
import time
import os

pyautogui.hotkey("win")
time.sleep(1.5)
pyautogui.write("goo")
time.sleep(2)
pyautogui.press("enter")
dir_path=os.path.dirname(os.path.realpath(__file__))
p=None

while p is None:
    p=pyautogui.locateOnScreen(dir_path+"/gmail2.png",confidence=0.10)

if p is not None:
    pyautogui.moveTo(p[0]+1160,p[1]+160,duration=0.5)
    time.sleep(5)
    
    pyautogui.click(p[0]+1160,p[1]+160,duration=0.5)

time.sleep(5)

s=None
while s is None:
    s=pyautogui.locateAllOnScreen(dir_path+"/square.png",confidence=0.10)
    
if s is not None:
    pyautogui.moveTo(p[0]+1080,p[1]+180,duration=0.5)
    time.sleep(5)
    pyautogui.click(p[0]+1080,p[1]+180,duration=0.5)

time.sleep(5)

a=None

while a is None:
    a=pyautogui.locateOnScreen(dir_path+"/point.png",confidence=0.10)

if a is not None:
    pyautogui.moveTo(p[0]+650,p[1]+180,duration=0.5)
    time.sleep(5)
    pyautogui.click(p[0]+650,p[1]+180,duration=0.5)

time.sleep(5)

#################

r=None

while r is None:
    r=pyautogui.locateOnScreen(dir_path+"/read.png",confidence=0.10)

if r is not None:
    pyautogui.moveTo(p[0]+650,p[1]+220,duration=0.5)
    time.sleep(1)
    pyautogui.click(a[0]+520,a[1]+220,duration=0.5)

time.sleep(2)

print("mission done ")
