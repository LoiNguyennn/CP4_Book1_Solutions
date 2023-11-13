from sys import stdin


if __name__ == '__main__':
    for line in stdin:
        line.strip()
        ans = eval(line)
        print("{:.2f}".format(ans))