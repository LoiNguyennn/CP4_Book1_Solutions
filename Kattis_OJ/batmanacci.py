fib = [0, 1]
for i in range(2, 100001):
    fib.append(fib[i - 1] + fib[i - 2])

ans = ['', 'N', 'A', 'NA']

if __name__ == '__main__':
    n, k = map(int, input().split())
    while (n > 3):
        if (k <= fib[n - 2]):
            n -= 2
        else:
            k -= fib[n - 2]
            n -= 1
    print(ans[n][k - 1])