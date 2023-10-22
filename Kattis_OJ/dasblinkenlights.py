from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

if __name__ == '__main__':
    p, q, s = map(int, input().split())
    if (lcm(p, q) <= s):
        print('yes')
    else:
        print('no')