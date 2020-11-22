'''
Assignment 5
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
def dec(str): 
    dec = 0
    for n in range(1,len(str)):
        dec += int(str[-n-1:-n]) * (2 ** n)
    dec += int(str[-1:])
    return dec

def check(str):
    for char in str:
        if char != '0' and char != '1':
            return False
    return True

while True:
    bin_str = input("Binary: ")
    split = []
    n = 0
    hex_list = []

    if check(bin_str):

        while n < len(bin_str):
            if n+4 > len(bin_str):
                split.append(bin_str[:len(bin_str) - n])
            elif n == 0:
                split.append(bin_str[-4:])
            else:
                split.append(bin_str[-n-4:-n])
            n += 4

        if len(bin_str) % 4 == 0:
            x = len(bin_str) // 4
        else:
            x = (len(bin_str) // 4) + 1

        for n in range(0,x):
            if dec(split[n]) < 10:
                hex_list.append(str(dec(split[n])))
            elif dec(split[n]) >= 10:
                hex_list.append(chr(dec(split[n]) + 55))

        hex_str = ''.join(hex_list)[::-1]

        print("Hexadecimal:",hex_str)

    elif bin_str == '-1':
        break

    else:
        print("Not Binary Number!")
