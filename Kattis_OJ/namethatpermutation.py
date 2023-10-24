from sys import stdin

left_numbers = []
f = []

def fillFactorial():
    f.extend([1, 1]);
    for i in range(2, 51):
        f.append(f[i - 1] * i) 


if __name__ == '__main__':
    fillFactorial()

    for line in stdin:
        n, k = map(int, line.split())
        ans = []
        for i in range(1, n + 1):
            left_numbers.append(i)

        while len(left_numbers):
            idx = k // f[n - 1]
            ans.append(left_numbers[idx])
            left_numbers.pop(idx)
            k %= f[n - 1]
            n -= 1
        print(*ans)
