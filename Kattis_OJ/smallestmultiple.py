from math import gcd
from sys import stdin

def lcm(a, b):
    return a * b // gcd(a, b)

if __name__ == '__main__':
    for line in stdin:
        a = [int(x) for x in line.split()]
        ans = 1
        for i in a:
            ans = lcm(ans, i)
        print(ans)