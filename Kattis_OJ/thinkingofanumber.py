from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0: 
            break
        l = 1
        r = 100000
        div = 1
        for _ in range(n):
            cmd = input().split()
            if cmd[0] == 'less':
                r = min(r, int(cmd[2]) - 1)
            elif cmd[0] == 'divisible':
                div = lcm(div, int(cmd[2]))
            elif cmd[0] == 'greater':
                l = max(l, int(cmd[2]) + 1)   

        if r == 100000:
            print('infinite', end = ' ')
        elif r < l:
            print('none', end = ' ')
        else:
            haveSolution = False
            for i in range(l, r + 1):
                if (i % div == 0):
                    print(i, end = ' ')
                    haveSolution = True
            if haveSolution == False:
                print('none', end = ' ')
        print('')