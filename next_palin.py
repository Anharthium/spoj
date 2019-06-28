import time

def main():
    tcase = eval(input())
    for i in range(tcase):
        num = input()
        print (next_palin(num))


def next_palin(num):
    A = list(num)
    A = [int(x) for x in A]
    num_len = len(A)
    i = 0
    j = num_len - 1
    right_incr = 0
    
    while (True):
        #print ("i = " + str(i) + " j = " + str(j))
        if (i == j or i > j):
            if (i == j and right_incr == 0): #contains odd no. of digits and no right-digit has been increased yet 
                                             #inner most dig for odd len num
                if (A[i] == 9):  #overflow, find the nearest tenth, hundredth, thousandth etc.
                    found = 0    #digit where we safely incremented without overflowing
                    for k in range(num_len-1, -1, -1):
                        if (k >= i):
                            A[k] = 0
                        else:   #k < i
                            if A[k] != 9:
                                A[k] += 1
                                found = 1
                                break
                            else:
                                A[k] = 0
                    if (found == 0): #all digit's overflowed
                        A.insert(0, 1)  #insert a new digit
                    #we've found new num, continue from top
                    i = 0
                    j = len(A) - 1
                    #print(A)
                    continue
                else:
                    A[i] += 1
            break

        #innermost pair (i,j) for odd len num
        if (i+1 > j-1): #skip odd len num
            if (A[j] == A[i] and right_incr == 0):
                if (A[i] == 9):
                    found = 0    #digit where we safely incremented without overflowing
                    for k in range(num_len - 1, -1, -1):
                        if (k >= i):
                            A[k] = 0
                        else:   #k < i
                            if A[k] != 9:
                                A[k] += 1
                                found = 1
                                break
                            else:
                                A[k] = 0
                    if (found == 0): #all digit's overflowed
                        A.insert(0, 1)  #insert a new digit
                    #we've found new num, continue from top
                    i = 0
                    j = len(A) - 1
                    #print(A)
                    continue
                else:
                    A[j] += 1
                    A[i] += 1
            elif (A[j] < A[i]):   #right digit is less than left digit
                A[j] = A[i]
            elif (A[j] > A[i]):
                #try to find nearest digits where A[i] == A[j]. Eg. 11, 22, 33 etc.
                if (A[j] - A[i] == 1):
                    A[i] = A[j]
                else:
                    while (A[i] != A[j]):
                        A[i] = A[i] + 1
                        A[j] = A[j] - 1
        #one of outer pairs (i, j)
        else:
            if (A[j] > A[i]):   #right digit can be decreased
                A[j] = A[i]
            elif (A[j] < A[i]):
                A[j] = A[i]
                right_incr += 1
        
        #increment loop counters
        i += 1
        j -= 1

    num = ""
    for dig in A:
        num += str(dig)

    return num
    
main()

"""
def next_palin_brute(num):
    num = num+1
    while True:
        num_cpy = num
        palin = 0
        num = list(str(num))
        i = 0 
        j = len(num) - 1
        while (True):
            if (i == j or i > j):
                palin = 1
                break
            if (num[i] != num[j]):
                break
            else:
                i = i+1
                j = j-1
        
        if palin == 1:
            return num_cpy
        else:
            num = num_cpy+1

def test():
    num = [808, 2133, 36457347, 2934798349832498, 1, 51253615361237625376215376215178876236]
    
    for i in range(len(num)):
        #next_pal_br = 0
        start = time.time()
        next_pal    = next_palin(str(num[i]))
        tm_taken_sm = time.time() - start
        
        print ("num = {}, next_palin_sm = {}, time = {} msec". \
                format(num[i], next_pal, tm_taken_sm*1000))
        
        start = time.time()
        next_pal_br = next_palin_brute(num[i])
        tm_taken_br = time.time() - start

        print ("num = {}, next_palin_brute = {}, time = {} msec". \
                format(num[i], next_pal_br, tm_taken_br*1000))

        print("-"*100)

test()
"""
