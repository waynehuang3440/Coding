'''
Assignment 3
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
def find_prime(i):
    if i == 1:
        return False
    for n in range(2,i):
        if i % n == 0:
            return False
    return True

def find_factor(x,i):
    if x % i == 0:
        return True
    else:
        return False
        

x = int(input("input: "))

for i in range(1,x + 1):
    if find_factor(x,i):
        if find_prime(i):
            print(i, "Y")
        else:
            print(i, "N")
