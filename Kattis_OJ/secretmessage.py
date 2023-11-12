from math import sqrt

if __name__ == '__main__':
    TC = int(input())
    for _ in range(TC):
        mess = input()
        L = len(mess)
        for M in range(L, 2 * L):
            x = int(sqrt(M))
            if x * x == M:
                for j in range(M - L):
                    mess += '*'
                break

        N = int(sqrt(len(mess)))
        arr = [[0 for j in range(N)] for i in range(N)]
        
        idx = 0 
        for j in reversed(range(N)):
            for i in range(N):
                arr[i][j] = mess[idx]
                idx += 1

        for i in range(N):
            for j in range(N):
                if arr[i][j] != '*':
                    print(arr[i][j], end = '')
        print()