if __name__ == '__main__':
    n = int(input())
    f = [1, 1]
    for i in range(2, 10001):
        f.append(f[i - 1] * i)
    ans = 0 
    for i in range(0, n + 1):
        ans = ans + 1 / f[i]
    print(ans)
