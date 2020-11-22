def bin_check(str):
    for char in str:
        if char != '0' and char != '1':
            return False
    return True



while 1:
    bin_str = input("Bianry: ")
    dec = 0

    if bin_str == '-1':
        break

    for n in range(1,len(bin_str)):
        if bin_check(bin_str) == False:
            print("Not Binary Number!")
            break

        dec += int(bin_str[-n-1:-n]) * (2 ** n)
    else:
        dec += int(bin_str[-1:])
        print("Decimal:",dec)
    
