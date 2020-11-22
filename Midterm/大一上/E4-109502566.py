file = open('text.txt','r')

loop_times = 1
for readline in file:
    
    print("----------looped",loop_times,"times----------")

    split = readline.split()
    line = split[0]

    operation_small = []
    operation_big = []
    n = 0
    level = []
    level_count = 0

    while n < len(line):
        if line[n] == '(' or line[n] == ')':
            n = n + 1
            
        else:
            flag = 0
            level_count = 0

            for x in range(0,n):
                if line[x] == '(':
                    level_count += 1
                elif line[x] == ')':
                    level_count -= 1
            level.append(level_count)
    
            for m in range(n,len(line)):
                if line[m] == '(' or line[m] == ')':
                    break
                operation_small.append(line[m])
                flag += 1
            operation_small_str = "".join(operation_small)
            if operation_small_str != '':
                operation_big.append("".join(operation_small))
            operation_small = []
            n = n + flag

    num = []
    print(operation_big)

    operation_big_len = len(operation_big)
    index = 0
    sep = []
    while index < operation_big_len:
        if len(operation_big[index]) > 1:
            sep = []
            if operation_big[index][0] == '+' or operation_big[index][0] == '-' or operation_big[index][0] == '*' or operation_big[index][0] == '/':
                sep.append(operation_big[index][0])
                sep.append(operation_big[index][1:])
                del operation_big[index]
                operation_big.insert(index, sep[1])
                operation_big.insert(index, sep[0])
                level.insert(index, level[index])
                operation_big_len += 1

            elif operation_big[index][-1] == '+' or operation_big[index][-1] == '-' or operation_big[index][-1] == '*' or operation_big[index][-1] == '/':
                sep.append(operation_big[index][:-1])
                sep.append(operation_big[index][-1])
                del operation_big[index]
                operation_big.insert(index, sep[1])
                operation_big.insert(index, sep[0])
                level.insert(index, level[index])
                operation_big_len += 1

        index += 1

    print(operation_big)

    for n in range(0,len(operation_big)):
        
        try:
            num.append(int(operation_big[n]))
        except:
            for m in range(0,len(operation_big[n])):
                if len(operation_big[n]) == 1:
                    num.append(operation_big[n])
                elif operation_big[n][m] == '+':
                    try:
                        result = int(operation_big[n][:m]) + int(operation_big[n][m+1:])
                        num.append(result)
                    except:
                        num.append(operation_big[n][m])
                elif operation_big[n][m] == '-':
                    try:
                        result = int(operation_big[n][:m]) - int(operation_big[n][m+1:])
                        num.append(result)
                    except:
                        num.append(operation_big[n][m])
                elif operation_big[n][m] == '*':
                    try:
                        result = int(operation_big[n][:m]) * int(operation_big[n][m+1:])
                        num.append(result)
                    except:
                        num.append(operation_big[n][m])

                elif operation_big[n][m] == '/':
                    try:
                        result = int(operation_big[n][:m]) / int(operation_big[n][m+1:])
                        num.append(result)
                    except:
                        num.append(operation_big[n][m])
   
    max_level = level[0]
    for n in range(0,len(level)):
        max_level = max(max_level, level[n])

    print(num)
    print(level)

    count = max_level
    num_len = len(num) 
    while count > 0:
        if num_len == 1:
            break

        n = 0
        while n < num_len:

            if level[n] == count:
                print(n)
                if n == 0:
                    if num[n+1] == '+':
                        result = num[n] + num[n+2]
                    elif num[n+1] == '-':
                        result = num[n] - num[n+2]
                    elif num[n+1] == '*':
                        result = num[n] * num[n+2]
                    elif num[n+1] == '/':
                        result = num[n] / num[n+2]

                    del num[n+2]
                    del level[n+2]
                    del num[n+1]
                    del level[n+1]
                    del num[n]
                    del level[n]

                    num.insert(n, result)
                    level.insert(n, count-1)
                    num_len = num_len - 2

                elif n == num_len-1:

                    if num[n-1] == '+':
                        result = num[n-2] + num[n]
                    elif num[n-1] == '-':
                        result = num[n-2] - num[n]
                    elif num[n-1] == '*':
                        result = num[n-2] * num[n]
                    elif num[n-1] == '/':
                        result = num[n-2] / num[n]

                    del num[n]
                    del level[n]
                    del num[n-1]
                    del level[n-1]
                    del num[n-2]
                    del level[n-2]

                    num.insert(n-2, result)
                    level.insert(n-2, count-1)
                    num_len = num_len - 2

                
                elif level[n+1] >= level[n-1]:            
                    if num[n+1] == '+':
                        result = num[n] + num[n+2]
                    elif num[n+1] == '-':
                        result = num[n] - num[n+2]
                    elif num[n+1] == '*':
                        result = num[n] * num[n+2]
                    elif num[n+1] == '/':
                        result = num[n] / num[n+2]
    
                    del num[n+2]
                    del level[n+2]
                    del num[n+1]
                    del level[n+1]
                    del num[n]
                    del level[n]

                    num.insert(n, result)
                    level.insert(n, count-1)
                    num_len = num_len - 2
                    
                elif level[n+1] < level[n-1]:
                    if num[n-1] == '+':
                        result = num[n-2] + num[n]
                    elif num[n-1] == '-':
                        result = num[n-2] - num[n]
                    elif num[n-1] == '*':
                        result = num[n-2] * num[n]
                    elif num[n-1] == '/':
                        result = num[n-2] / num[n]

                    del num[n]
                    del level[n]
                    del num[n-1]
                    del level[n-1]
                    del num[n-2]
                    del level[n-2]

                    num.insert(n-2, result)
                    level.insert(n-2, count-1)
                    num_len = num_len - 2
                print(num)
                print(level)

            n += 1
        count -= 1

    result = num[0]
    print("RESULT =",result)
    loop_times += 1

file.close()
