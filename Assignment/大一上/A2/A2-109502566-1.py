'''
Assignment 2
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
import random 

num = random.randint(1,100)
n = 1

while 1:
    str = input("輸入一數字:")
    guess = int(str)
    
    if guess < num:
        print("比",guess,"還要大")
    elif guess > num:
        print("比",guess,"還要小")
    else:
        print("猜對了！總共猜了",n,"次")
        break

    n += 1

