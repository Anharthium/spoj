
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
    nlen[1] = len(num[1])

    # convert to int
    num[0] = int(num[0])
    num[1] = int(num[1])
    
    if (operator == '+'):
        result = num[0] + num[1]
    else: # operator '-'
        result = num[0] - num[1]
    
    num[2] = str(result) # to string
    nlen[2] = len(num[2])

    # convert back to str
    num[0] = str(num[0])
    num[1] = str(num[1])

    # calc. leading spaces and form final string
    spaces = 0 # num of spaces
    op_app = False # have we appended operator
    max_len = max(nlen)
    for i in range(3):
        spaces = max_len - nlen[i]
        if (i == 1 and not op_app): # second number contains operator
            num[i] = operator + num[1]
            op_app = True
            
        if (i == 1):
            num[i] = (' '*(spaces-1)) + num[i] # one space less since it already has operator appended
        else:
            num[i] = (' '*spaces) + num[i]

    for i in range(4):
        if (i <= 1):
            print(num[i])
        elif (i == 2):
            print("-"*max_len) # print req. num of '-'
        else:
            print(num[i-1])

    print()


def big_num_mul(num):
    """
    big number multiplication
    """
    
    nlen = [0, 0, 0] # input numbers and its result
    nlen[0] = len(num[0])
    nlen[1] = len(num[1])
    num_temp = [0]*nlen[1] # for intermediate numbers during multiplication
    
    # convert to int
    num[0] = int(num[0])
    num[2] = 0 # to contain the final result

    # calculate temp_numbers and final result
    for i in range(1, nlen[1] + 1):
        num_temp[i-1] = num[0] * int(num[1][-i])
        num[2] += num_temp[i-1] # final result
    
    num[1] = int(num[1])

    dashes = max(num) # number of dashes to print
     
    # convert back to str
    num[0] = str(num[0])
    num[1] = str(num[1])
    num[2] = str(num[2]) 
    nlen[2] = len(num[2])

    # calc. trailing spaces for intermediate numbers
    num_temp_len = len(num_temp)
    for i in range(num_temp_len):
        num_temp[i] = str(num_temp[i]) + (" " * i) # to str
    
    len_temp = [len(i) for i in num_temp] # list of length of temp numbers

    # calc. leading spaces for every num
    max_len = max(dashes, max(len_temp))
    for i in range(len(num)):
        spaces = max_len - len(num[i])
        if (i == 1):
            num[i] = '*' + num[i] # attach operator
            num[i] = (" " * (spaces-1)) + num[i] # attach leading spaces
        else:
            num[i] = (" " * spaces) + num[i] # attach leading spaces
    
    # calc. leading spaces for intermediate nums
    for i in range(num_temp_len):
        spaces = max_len - len(num_temp[i])
        num_temp[i] = (" " * spaces) + num_temp[i]
    
    # ------ printing starts ---------
    # print num
    for i in range(len(num)):
        if (i <= 1):
            print(num[i])
        elif (i == 2):
            print("-"*dashes) # print req. num of '-'
    
    # print temp numbers
    for i in range(num_temp_len):
        print(num_temp[i])

    # print dashes
    print("-" * max_len) # print req. num of '-'

    # print final result
    print(num[2])
    print()


main() # call main

