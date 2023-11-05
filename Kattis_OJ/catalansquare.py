if __name__ == '__main__':
    x = int(input())
    x += 1
    fact = [1, 1]
    for i in range(2, 2 * x + 1):
        fact.append(fact[-1] * i)

    print(fact[2 * x] // fact[x] // fact[x] // (x + 1))