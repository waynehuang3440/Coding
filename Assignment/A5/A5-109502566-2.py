'''
Assignment 5
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1001
'''
def add(num1, num2):    
    int_sum_list = list(str(num1 + num2))
    carry = 0
    bin_sum_list = []
    for x in range(1,len(int_sum_list) + 1):
        if carry > 0:
            int_sum_list[-x] = str(int(int_sum_list[-x]) + carry)
            carry = 0

        if int(int_sum_list[-x]) > 1:
            bin_sum_list.append(str(int(int_sum_list[-x]) - 2))
            carry = 1
        else:
            bin_sum_list.append(int_sum_list[-x])

    if carry > 0:
        bin_sum_list.append('1')

    bin_sum_str = "".join(bin_sum_list)[::-1]
    return bin_sum_str


while True:
    formula = input()
    n = 0
    
    if formula == '-1':
        break

    else:
        for char in formula:
            if char == '+' or char == '-':
                num1 = int(formula[:n])
                num2 = int(formula[n+1:])
                break
            n += 1

        if formula[n] == '+':
            bin_sum_str = add(num1, num2)

        elif formula[n] == '-':
            oc_list = []
            for char in str(num2):
                if char == '1':
                    oc_list.append('0')
                elif char == '0':
                    oc_list.append('1')
    
            oc_str = "".join(oc_list)
            oc_add1 = int(add(int(oc_str), 1))
            oc_add1_list = []

            if len(oc_str) > len(str(oc_add1)):
                for x in range(0, len(oc_str) - len(str(oc_add1))):
                    oc_add1_list.append('0')
            oc_add1_list += list(str(oc_add1))
            oc_add1_str = "".join(oc_add1_list)
    
            tc_list = []
            if len(str(num1)) > len(oc_add1_str):
                for x in range(0,len(str(num1)) - len(oc_add1_str)):
                    tc_list.append('1')
            tc_list += oc_add1_str
            tc = int("".join(tc_list))
    
            bin_sum_list = list(add(num1, tc))
            del bin_sum_list[0]
            bin_sum_str = str(int("".join(bin_sum_list)))

        print(bin_sum_str)
