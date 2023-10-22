import math
if __name__ == '__main__':
    while True:
        arr = list(map(int, input().split()));    
        if arr[0] == 0:
            break
        ans = 0
        for i in range(1, len(arr) - 1):
            ans = math.gcd(ans, arr[i] - arr[i - 1])
        print(ans)