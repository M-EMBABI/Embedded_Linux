import pyautogui
import time
import os
dir_path=os.path.dirname(os.path.realpath(__file__))

o=None
while o is None:
    o=pyautogui.locateOnScreen(dir_path+"/lib.png",confidence=0.7)

time.sleep(1)
if o is not None:
    pyautogui.moveTo(o[0]+10,o[1]+40,duration=0.10)
    pyautogui.click(o[0]+10,o[1]+40,duration=0.10)

time.sleep(1)
################################################################################
pyautogui.write("clangd")

o=None
while o is None:
    o=pyautogui.locateOnScreen(dir_path+"/clange.png",confidence=0.7)
    
if o is not None:
        pyautogui.moveTo(o[0]+150,o[1]+50,duration=0.10)
        pyautogui.click(o[0]+150,o[1]+50,duration=0.10)
        #################################################################################
time.sleep(1)


pyautogui.moveTo(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-19,duration=0.10)
time.sleep(0.5)
pyautogui.hotkey("delete")
##############################################################################

time.sleep(1)

pyautogui.write("testmate")

o=None
while o is None:
    o=pyautogui.locateOnScreen(dir_path+"/c++test.png",confidence=0.7)
    
if o is not None:
        pyautogui.moveTo(o[0]+150,o[1]+50,duration=0.10)
        pyautogui.click(o[0]+150,o[1]+50,duration=0.10)
#######################################################################################

time.sleep(1)


pyautogui.moveTo(o[0]+150,o[1]+-100,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-100,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-100,duration=0.10)
pyautogui.hotkey("delete")

#########################################################################################
time.sleep(1)

pyautogui.write("c++ helper")

o=None
while o is None:
    o=pyautogui.locateOnScreen(dir_path+"/c++helper.png",confidence=0.7)
    
if o is not None:
        pyautogui.moveTo(o[0]+150,o[1]+50,duration=0.10)
        pyautogui.click(o[0]+150,o[1]+50,duration=0.10)
        
#####################################################################################
time.sleep(1)


pyautogui.moveTo(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.hotkey("delete")
time.sleep(1)
pyautogui.hotkey("backspace")
time.sleep(0.5)
pyautogui.hotkey("backspace")
time.sleep(0.5)
pyautogui.hotkey("backspace")
pyautogui.hotkey("backspace")
#####################################################################################
time.sleep(6)

time.sleep(1)

pyautogui.write("cmake")

o=None
while o is None:
    o=pyautogui.locateOnScreen(dir_path+"/cmake.png",confidence=0.7)
    
if o is not None:
        pyautogui.moveTo(o[0]+150,o[1]+50,duration=0.10)
        pyautogui.click(o[0]+150,o[1]+50,duration=0.10)
##########################################################################################
time.sleep(2)

pyautogui.moveTo(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.click(o[0]+150,o[1]+-19,duration=0.10)
pyautogui.hotkey("delete")
pyautogui.hotkey("backspace")
pyautogui.hotkey("backspace")
pyautogui.hotkey("backspace")
pyautogui.hotkey("backspace")

############################################################################################

time.sleep(2)

time.sleep(1)

pyautogui.write("cmake tools")

o=None
while o is None:
    o=pyautogui.locateOnScreen(dir_path+"/cmaketools.png",confidence=0.7)
    
if o is not None:
        pyautogui.moveTo(o[0]+130,o[1]+50,duration=0.10)
        pyautogui.click(o[0]+130,o[1]+50,duration=0.10)

