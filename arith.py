def main():
    t = eval(input()) # test cases
    for i in range(t):
        expr = input()
        op = '' # operator
        op_index = 0 # operator index
        for char in expr:
            if char == '+' or char == '-' or char == '*':
                op = char
                break
            else:
                op_index += 1
        num = ['', '', ''] # empty list to contain input numbers and its result
        num[0] = expr[0:op_index]
        num[1] = expr[op_index+1:len(expr)]
        if (op == '+' or op == '-'):
            big_num_as(op, num)
        else:
            big_num_mul(num)


def big_num_as(operator, num):
    """
    big number addition and subtraction
    """
    
    nlen = [0, 0, 0]
    nlen[0] = len(num[0])
    nlen[1] = len(num[1]) + 1 # one plus for operator '+' or '-'

    # convert to int
    num[0] = int(num[0])
    num[1] = int(num[1])
    
    if (operator == '+'):
        result = num[0] + num[1]
    else: # operator '-'
        result = num[0] - num[1]
    
    num[2] = str(result) # to string
    nlen[2] = len(num[2])
    
    # number of dashes to print
    num_dashes = max(nlen[1], nlen[2])
    dashes = '-' * num_dashes

    # convert back to str
    num[0] = str(num[0])
    num[1] = str(num[1])


    # calc. leading spaces and form final string
    op_app = False # have we appended operator
    max_len = max(nlen)
    for i in range(3):
        spaces = max_len - nlen[i]
        if (i == 1 and not op_app): # second number contains operator
            num[i] = operator + num[1]
            op_app = True
            
        num[i] = (' '*spaces) + num[i]

    # calc. leading spaces for dashes
    spaces = max_len - num_dashes
    dashes = ' ' * spaces + dashes
    
    # number of dashes to print
    # dashes = max(len(num[1]), len(num[2]))
    
    # printing starts
    for i in range(4):
        if (i <= 1):
            print(num[i])
        elif (i == 2):
            print(dashes) # print req. num of '-'
        else:
            print(num[i-1])

    print() # last line


def big_num_mul(num):
    """
    big number multiplication
    """
    
    nlen = [0, 0, 0] # length of input numbers and its result
    nlen[0] = len(num[0])
    nlen[1] = len(num[1]) + 1 # plus 1 for operator '*'
    num_temp = [0]*(nlen[1] - 1) # for intermediate numbers during multiplication
    
    skip = 0 # should I skip temp. numbers printing? 0 for No, 1 for yes
    if (nlen[1] == 2): # second number has only one digit
        skip = 1
    
    # convert to int
    num[0] = int(num[0])
    num[2] = 0 # to contain the final result

    # calculate temp_numbers and final result
    for i in range(1, nlen[1]):
        num_temp[i-1] = num[0] * int(num[1][-i])
        # exponentiation by 10 represents 
        # that many zeroes at the end
        add_mul = num_temp[i-1] * (10**(i-1))
        num[2] += add_mul # final result

    # convert back to str
    num[0] = str(num[0])
    num[1] = str(num[1])
    num[2] = str(num[2]) 
    nlen[2] = len(num[2])
    
    num_dashes1 = max(nlen[1], len(str(num_temp[0]))) # number of first dashes to print is the 
                                                      # maximum of top number and botom number
    dashes1 = '-' * num_dashes1
    
    # calc. dashes2
    num_dashes2 = max(len(str(num_temp[-1])), len(num[-1]))
    dashes2 = '-' * num_dashes2

    # calc. trailing spaces for intermediate numbers
    num_temp_len = len(num_temp)
    for i in range(num_temp_len):
        num_temp[i] = str(num_temp[i]) + (' ' * i) # space to add at tail = i
    
    len_temp = [len(i) for i in num_temp] # list of length of temp numbers
    
    # --------------- prepare final strings with apt number of spaces inserted ---------------

    # calc. and prepare leading spaces for every num
    max_len = max(max(nlen), max(len_temp))
    
    for i in range(len(num)):
        spaces = max_len - nlen[i]
        if (i == 1):
            num[i] = '*' + num[i] # attach operator
        num[i] = (' ' * spaces) + num[i] # attach leading spaces

    # calculate and prepare leading spaces for dashes1
    spaces = max_len - num_dashes1
    dashes1 = (' ' * spaces) + dashes1
    
    # calculate and prepare leading spaces for dashes2
    spaces = max_len - num_dashes2
    dashes2 = (' ' * spaces) + dashes2
    
    # calc. leading spaces for intermediate nums
    for i in range(num_temp_len):
        spaces = max_len - len(num_temp[i])
        num_temp[i] = (' ' * spaces) + num_temp[i]

    
    # ------ printing starts ---------
    # print num
    for i in range(len(num)):
        if (i <= 1):
            print(num[i])
        elif (i == 2): # print dashes1
            print(dashes1)

    # print temp numbers; skip if only one temp_num present
    if (skip == 0):
        for i in range(num_temp_len):
            print(num_temp[i])

    # print dashes2; skip if only one temp_num present
    if (skip == 0):
        print(dashes2)

    # print final result
    print(num[2])
    
    print() # for last line


main() # call main

