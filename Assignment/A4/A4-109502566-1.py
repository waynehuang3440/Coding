'''
Assignment 4
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
file1 = open('score.txt','r')
file2 = open('score_109502566.txt','w')

line = file1.readline()
file2.write(line[:-1]+"\n")

sum = 0
for line in file1:
    split = line.split()
    file2.write(split[0]+' ')
    for n in range(1,5):
        sum = sum + int(split[n])
        file2.write(split[n]+' ')
    ave = sum/4
    file2.write(str(ave)+"\n")
    sum = 0

file1.close()
file2.close()
