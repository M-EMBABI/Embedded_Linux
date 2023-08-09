#system if the data entry is correct the person can pass

user =input("ypur name please: ")
passward =int(input("your passward please: "))
if user == "ahmed" or "ali" or "amr":
    if user == "ahmed":
        if  passward == 1394:
            print("Welcome Ahmed in your system ")
    elif user == "ali":
        if  passward == 6078:
            print("Welcome Ali in your system ") 
    elif user == "amr":
        if  passward == 9345:
            print("Welcome Amr in your system ")
else:
    pass
