from sys import stdin
from math import log10
from math import floor

if __name__ == '__main__':
    l = [0]
    cur = 0
    for i in range(1, 1000001):
        l.append(l[-1] + log10(i)) 

    for line in stdin:
        n = int(line)
        print(floor(l[n]) + 1)