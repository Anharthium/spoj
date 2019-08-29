from math import factorial, log

#def calc_trail_0_br(x):
#    """
#    Brute force method to calculate trailing zeroes in factorial of x.
#    """
#    fact = str(factorial(x))
#    fact = fact[::-1]
#    trail_zero = 0
#    for dig in fact:
#        if dig == '0':
#            trail_zero += 1
#        else:
#            return trail_zero

# look up table for number of fives
# in prime factorization of any multiple of 5.
num_five_prfct = {5:1, 10:1}


def five_in_prfct(x):
    """
    function to calculate number of 5's in prime factorization of x.
    """
    num_five = 0
    orig_num = x

    # non multiples of 5 can't produce factor '5'.
    while (True):
        if (x%5 != 0):
            break
        else:
            if x in num_five_prfct:

            num_five += 1
            x = x//5
    
    # store in the look up table
    num_five_prfct[orig_num] = num_five

    return num_five

def calc_trail_0_sm(x):
    """
    A smart way to calculate trailing zeroes in factorial of x.
    """
    start_num = x - (x%5)   # nearest multiple of 5 <= x

    trail_zero = 0

    for i in range(start_num, 0, -5):
        if i in num_five_prfct:
            trail_zero += num_five_prfct[i]
        else:
            trail_zero += five_in_prfct(i)

    return trail_zero


#def main():
#    """
#    Driver function.
#    """
#    
#    for i in range(1, 10000):
#        br = calc_trail_0_br(i)
#        sm = calc_trail_0_sm(i)
#        if (br != sm):
#            print("num = {}, trail_0_br = {}, trail_0_sm = {}".format(i, br, sm))


def main():
    t_case = eval(input())
    for i in range(t_case):
        i_num = eval(input())
        print(calc_trail_0_sm(i_num))


main() # call main

