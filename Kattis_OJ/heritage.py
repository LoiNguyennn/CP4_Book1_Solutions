from functools import lru_cache

d = {}
MOD = int(1e9 + 7)

@lru_cache(maxsize = None)
def dp(sub):
    ans = 0
    if sub in d:
        ans += d[sub]
    for i in range(len(sub) + 1):
        if sub[:i] in d:
            ans += d[sub[:i]] * dp(sub[i:])
            ans %= MOD
    return ans

if __name__ == '__main__':
    n, name = input().split()
    n = int(n)
    for i in range(n):
        s, v = input().split()
        d[s] = int(v)
    print(dp(name))