str = input()
split = str.split()

or_output = []
and_output = []
xor_output = []

for n in range(0,len(split[0])):
    if split[0][n] == split[1][n]:
        if split[0][n] == '1':
            or_output.append('1')
            and_output.append('1')
            xor_output.append('0')
        else:
            or_output.append('0')
            and_output.append('0')
            xor_output.append('0')

    else:
        or_output.append('1')
        and_output.append('0')
        xor_output.append('1')

or_str = "".join(or_output)
and_str = "".join(and_output)
xor_str = "".join(xor_output)

print("OR:",or_str,"\nAND:",and_str,"\nXOR:",xor_str)

