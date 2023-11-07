from collections import Counter

if __name__ == '__main__':
    TC = int(input())
    for _ in range(TC):
        n = int(input())
        counter = Counter()
        for __ in range(n):
            a, b = input().split()
            counter[b] += 1
        ans = 1
        for v in counter.values():
            ans *= (v + 1)
        ans -= 1
        print(ans)