def solve(n, m):
    if n % m == 0: 
        return True
    if n > (2 * m): 
        return True
    return not solve(m, n - m)

if __name__ == '__main__':
    n, m = map(int, input().split())
    n, m = (max(n, m), min(n, m))
    
    if (solve(n, m)):
        print('win')
    else:
        print('lose')    
