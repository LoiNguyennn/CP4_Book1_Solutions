if __name__ == '__main__':
    fact = [1, 1]
    for i in range(2, 201):
        fact.append(fact[-1] * i)

    tc = int(input())
    for _ in range(tc):
        l = list(map(int, input().split()))
        n = l[0]
        k = l[1]
        black = 0 
        for i in range(2, len(l)):
            black += l[i]
        if (black > n):
            print(0)
            continue

        white = n - black
        if white - k + 1 < 0:
            print(0)
        else:
            print(fact[white + 1] // fact[k] // fact[white + 1 - k])