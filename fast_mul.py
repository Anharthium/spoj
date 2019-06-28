
def main():
    t = eval(input())
    
    for i in range(t):
        num = list(map(int, input().split(" ")))
        result = 1
        for mem in num:
            result *= mem

        print (result)


main()
