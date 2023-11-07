from sys import stdin
from collections import Counter

if __name__ == '__main__':
    fact = [1, 1]
    for i in range(2, 101):
        fact.append(fact[-1] * i)

    for line in stdin:
        line = line.strip()
        counter = Counter(line)
        ans = fact[len(line)]
        for v in counter.values():
            ans //= fact[v]
        print(ans)