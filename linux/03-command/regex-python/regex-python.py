#!/bin/python3
import re 
address = "22,st salah salem -giza"

pattern = r'^\d{1,4},st [a-zA-Z ]+-[a-zA-Z]+$'

if re.match(pattern,address):
        print("valid")
else:
        print("invalid")







