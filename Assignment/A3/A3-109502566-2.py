'''
Assignment 3
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
file = open("text.txt",'r')

find = input("find: ")
change = input("change to: ")
count = 0

for n in range(1,6):
    line = file.readline()
    print(line, end ='')
    x = line.find(find)

    while x < len(line):
        if x == -1:
            break
        line = line[0:x] + change + line[x+len(find):]
        count += 1
        x = line.find(find,x+1)
    
    print(line)

print("change count:",count)

file.close()
