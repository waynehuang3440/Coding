'''
Practice 4
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1003-B
'''

def func(a,o,b,c):
    if o == '+':
        if a+b==c: return True
    elif o == '-': 
        if a-b==c: return True
    elif o == '*':
        if a*b==c: return True
    else:
        return False

file1 = open('test.txt','r')
file2 = open('ans-109502566.txt','w')

for equation in file1:
    split = equation.split()
    if func(int(split[0]),split[1],int(split[2]),int(split[4])):
        file2.write("T\n")
    else:
        file2.write("F\n")

file1.close()
file2.close()
