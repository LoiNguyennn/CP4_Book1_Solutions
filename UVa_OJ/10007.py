from sys import stdin

if __name__ == '__main__':
    fact = [1, 1]
    dp = [1, 1]

    for i in range(2, 301):
        fact.append(fact[-1] * i)
        c = 0
        for j in range(i):
            c += dp[j] * dp[i - j - 1]
        dp.append(c)

    for n in stdin:
        n = int(n)
        if n == 0:
            break
        print(dp[n] * fact[n])