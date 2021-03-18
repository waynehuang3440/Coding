'''
	Assignment 13
	Name: 黃君翰
	Student Number: 109502566
	Course 2020-CE1001
'''
import re
str1 = input()
str2 = input().replace( '?', '.' ).replace( '*', '.*' )
if str1 in re.findall( str2, str1 ):
	print( 'true\n')
else:
	print( 'false\n' )