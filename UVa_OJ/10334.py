from sys import stdin

if __name__ == '__main__':
    fib = [1, 2]
    for i in range(2, 1001):
        fib.append(fib[i - 1] + fib[i - 2])
    for n in stdin:
        n = int(n)
        print(fib[n])