ans = {}

if __name__ == '__main__':    
    f = 1
    for i in range(1, 1000006):
        f *= i
        while (f % 10 == 0):
            f //= 10
        ans[i] = f % 10
        f %= 1000000


    while True:
        n = int(input())
        if n == 0:
            break
        print(ans[n])
