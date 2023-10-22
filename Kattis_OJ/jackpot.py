from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

if __name__ == '__main__':
    TC = int(input())
    while TC > 0:
        TC -= 1

        w = int(input())
        p = list(map(int, input().split()))
        ans = 1
        for i in range(len(p)):
            ans = lcm(ans, p[i])
        if (ans <= 1000000000):
            print(ans)
        else:
            print('More than a billion.')