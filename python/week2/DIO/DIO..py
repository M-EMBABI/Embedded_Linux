print("chose pin if in or out: ")

in_put=['in','0']
out_put=['out','1']
ddr=0
i=0

while i<8:
    pinconfig=str(input(f'port A pin{i}: ' )).format().strip()
    if pinconfig in in_put:
        ddr &= ~(0<<(i))
    elif pinconfig in out_put:
        ddr |= (1<<(i))
    else:
        i -= 1
    i+=1
    
ddr="{0:b}".format(ddr)
Driver="DIO.c"
port="PORTA"

with open (Driver,mode="w") as r:
    r.write(f'void init{port} DIR (void)\n')
    r.write("{")
    # [-1] considration on A  
    r.write(f'\n\t DDR{port[-1].capitalize()}={ddr};\n')
    r.write("}")  
