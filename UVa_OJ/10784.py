from sys import stdin

if __name__ == '__main__':
    tc = 1
    for N in stdin:
        N = int(N)
        if N == 0: break
        
        lo = 3
        hi = 1000000000000000000
        ans = 0
        while (lo <= hi):
            mi = (lo + hi) // 2
            if (mi * (mi - 3) // 2 >= N):
                ans = mi 
                hi = mi - 1
            else:
                lo = mi + 1 
        print(f'Case {tc}: {ans}')
        tc += 1