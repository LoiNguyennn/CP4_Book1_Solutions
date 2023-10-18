AL = {}
match = {}
vis = {}

def AugmentingPath(L):
	if vis[L]: return 0
	vis[L] = 1
	for R in AL[L]:
		if match[R] == -1 or AugmentingPath(match[R]):
			match[R] = L 
			return 1
	return 0

if __name__ == '__main__':
	n, m = map(int, input().split())
	AL.update({i:[] for i in range(n + 1)})
	for u in range(1, n + 1):
		t = list(map(int, input().split()))
		for v in range(1, len(t)):
			AL[u].append(t[v])
	match.update({i: -1 for i in range(m + 1)})
	
	MCBM = 0
	for i in range(1, n + 1):
		vis.update({i: 0 for i in range(1, n + 1)})
		MCBM += AugmentingPath(i)
	print(MCBM)