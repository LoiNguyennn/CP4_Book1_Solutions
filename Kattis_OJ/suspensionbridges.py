import math

def f(a, s, d):
    return a + s - a * math.cosh(d / (2 * a))


if __name__ == "__main__":
    d, s = map(int, input().split())
    l, r = 0, 10000000
    for i in range(0, 100, 1):
        mid = (l + r) / 2
        if f(mid, s, d) >= 0:
            r = mid 
        else:
            l = mid
    print(2 * l * math.sinh(d / (2 * l)))