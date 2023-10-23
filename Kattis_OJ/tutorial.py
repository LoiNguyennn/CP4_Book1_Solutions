import math

def type1(n, m):
    ai = 1
    for i in range(2, n + 1):
        ai *= i
        if ai > m:
            return ai
    return ai

if __name__ == '__main__':
    m, n, t = map(int, input().split())
    total = 0
    if t == 1:
        total = type1(n, m)
    elif t == 2:
        total = 2 ** n
    elif t == 3:
        total = n ** 4
    elif t == 4:
        total = n ** 3
    elif t == 5:
        total = n ** 2
    elif t == 6:
        total = n * math.log2(n)
    else:
        total = n
    if (total <= m):
        print('AC')
    else:
        print('TLE')