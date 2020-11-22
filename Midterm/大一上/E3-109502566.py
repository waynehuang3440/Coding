def check(a,b):
    for n in range(0,len(a)):
        if int(a[n]) >= b:
            return False
    return True

def dec(a,b):
    dec = 0
    for n in range(1,len(a)):
        if n+1 <= len(a):
            dec += int(a[-n-1]) * (b ** n)
    dec += int(a[-1])
    return dec
while 1:
    num_str = input()
    if num_str == '-1':
        break
    
    if check(num_str,4):
        print(dec(num_str,4))
    else:
        print("不是4進位數")        
        if check(num_str,9):
            print(dec(num_str,9))
        else:
            print("不是9進位數")
