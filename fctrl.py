from math import factorial, log

"""
def calc_trail_0_br(x):
    fact = str(factorial(x))
    fact = fact[::-1]
    trail_zero = 0
    for dig in fact:
        if dig == '0':
            trail_zero += 1
        else:
            return trail_zero
"""

def calc_trail_0_sm1(x):
    """
    A smart way to calculate trailing zeroes in factorial of x [version1].

    number of trailing zeroes = 5's contributed by multiples of 5 in the factorial
    i.e x/5 + x/25 + x/125 + x/625 + ...
    """
    
    trail_zero = 0
    i = 5
    while (True):
        contri_5 = x//i
        if (contri_5 == 0):
            break
        trail_zero += contri_5
        i = i*5

    return trail_zero

"""
def main():
    for i in range(1, 10000):
        br = calc_trail_0_br(i)
        sm = calc_trail_0_sm1(i)
        print("num = {}, trail_0_br = {}, trail_0_sm = {}".format(i, br, sm))
"""

def main():
    t_case = eval(input())
    for i in range(t_case):
        i_num = eval(input())
        print(calc_trail_0_sm1(i_num))

main() # call main

