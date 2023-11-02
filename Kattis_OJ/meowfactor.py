if __name__ == '__main__':
    n = int(input())
    ans = 1
    for i in range(1, 130):
        if (n % (i**9) == 0):
            ans = i
    print(ans)