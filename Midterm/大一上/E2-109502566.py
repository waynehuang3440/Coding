h = int(input())
n = h
m = 1

while n >= 1:
    print(" "*(n-1),"*"*m," "*(n-1))
    n = n - 1
    m = m + 2

for x in range(1,h):
    print(" "*((h+1)//2),"*"*(h-2)," "*((h+1)//2))
