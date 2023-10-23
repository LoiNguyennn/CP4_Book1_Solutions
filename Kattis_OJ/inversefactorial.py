import math

factorial_length = {} #factorial_length[n] = len(n!)

if __name__ == '__main__':
    cur_len = 0
    for i in range(1, 100000000):
        cur_len += math.log10(i)
        if (not math.floor(cur_len) in factorial_length):
            factorial_length[math.floor(cur_len)] = [i]
        else:
            factorial_length[math.floor(cur_len)].append(i)
        if (cur_len > 1e6):
            break
    n = input()
    if (len(factorial_length[len(n) - 1]) == 1):
        print(factorial_length[len(n) - 1][0])
    else:
        n = int(n)
        for i in range(1, 11):
            if (math.factorial(i) == n):
                print(i)
                break