if __name__ == '__main__':
    fact = [1, 1]
    for i in range(2, 10001):
        fact.append(fact[-1] * i)

    q = int(input())
    for _ in range(q):
        x = int(input())
        print(fact[2 * x] // fact[x] // fact[x] // (x + 1))
