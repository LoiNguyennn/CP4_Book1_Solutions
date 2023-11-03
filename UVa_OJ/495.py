from sys import stdin
if __name__ == '__main__':
    fib = [0, 1]
    for i in range(2, 5001):
        fib.append(fib[i - 1] + fib[i - 2])
    for n in stdin:
        n = int(n)
        print(f'The Fibonacci number for {n} is {fib[n]}')