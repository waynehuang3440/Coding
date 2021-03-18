'''
Assignment 4
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
file = open('score_109502566.txt','r')

search = input("查詢項目: ")
name = input("姓名: ")

subject = file.readline().split()

for line in file:
    split = line.split()
    if split[0].lower() == name.lower():
        for n in range(1,6):
            if subject[n].lower() == search.lower():
                print(split[0],subject[n],split[n])

file.close()
