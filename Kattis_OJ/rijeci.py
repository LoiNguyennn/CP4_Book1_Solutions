if __name__ == '__main__':
    k = int(input())
    a = 1
    b = 0
    for i in range(2, k + 1): 
        b = b + a 
        a = b - a 
    print(b, a + b)