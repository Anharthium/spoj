
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

        num1 = expr[0:op_index]
        num2 = expr[op_index+1:len(expr)]
        print("num1 = {}, num2 = {}".format(num1, num2))


def add_big_num(num1, num2):
    nlen = [0, 0, 0]
    nlen[0] = len(num1)
    nlen[1] = len(num2)

    # convert to int
    num1 = int(num1)
    num2 = int(num2)
    
    result = num1 + num2
    nlen[2] = len(str(result))

    spaces = [0, 0, 0]
    max_len = max(nlen)
    for i in range(3):
        spaces[i] = max_len - nlen[i]

    # printing starts
    for ln_cnt in range(4):
        if ln_cnt <= 1:


main() # call main

