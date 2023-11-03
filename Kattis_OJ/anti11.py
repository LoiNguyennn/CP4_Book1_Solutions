MOD = (10**9 + 7)
if __name__ == '__main__':
    TC = int(input())
    fib = [0, 2, 3]
    for i in range(3, 10001):
        fib.append((fib[i - 1] + fib[i - 2]) % MOD)
    for _ in range(TC):
        n = int(input())
        print(fib[n])