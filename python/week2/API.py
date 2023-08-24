import requests

# GET request
r = requests.get("https://api.ipify.org/?format=json")


print(r)

print(r.content)

x=input("enter your id: ")
print(x)

z=requests.get("https://ipinfo.io/"+str(x)+"/geo")

print(z)
print(z.content)
