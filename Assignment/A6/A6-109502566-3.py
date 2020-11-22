'''
	Assignment 6
	Name: 黃君翰
	Student Number: 109502566
	Course: 2020-CE1001
'''

def flip(str, dice):
	if str == 'north':
		dice[0], dice[1], dice[5], dice[3] = dice[3], dice[0], dice[1], dice[5] 
	elif str == 'east':
		dice[0], dice[2], dice[5], dice[4] = dice[4], dice[0], dice[2], dice[5]
	elif str == 'south':
		dice[0], dice[3], dice[5], dice[1] = dice[1], dice[0], dice[3], dice[5]
	elif str == 'west':
		dice[0], dice[4], dice[5], dice[2] = dice[2], dice[0], dice[4], dice[5]

	return dice;

output = []
direction = ['Up','North','East','South','West','Down']

while 1:
	n = int(input())
	
	if n == 0:
		break

	dice = [1,2,3,5,4,6] 
	dice_chr_list = []

	for i in range(0,n):
		flip_dir = input()
		dice = flip(flip_dir, dice)

	for i in range(0,6):
		dice_chr_list.append(str(dice[i]))

	output.append(dice_chr_list)

for i in range(0,len(output)):
	for j in range(0,6):
		print(direction[j]+": "+output[i][j],end=" ")
	print()