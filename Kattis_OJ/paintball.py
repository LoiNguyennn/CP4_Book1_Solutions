AL = {}
vis = {}
match = {}

def AugmentingPath(L):
	if vis[L]:
		return 0
	vis[L] = True
	for R in AL[L]:
		if match[R] == -1 or AugmentingPath(match[R]):
			match[R] = L
			return 1
	return 0

if __name__ == '__main__':
	n, m = map(int, input().split())
	AL.update({i:[] for i in range(n)})
	for i in range(m):
		a, b = map(int, input().split())
		a -= 1
		b -= 1
		AL[a].append(b)
		AL[b].append(a)
	match.update({i: -1 for i in range(n)})

	MCBM = 0
	for i in range(n):
		vis.update({i: False for i in range(n)})
		MCBM += AugmentingPath(i)
	if MCBM !=  n:
		print('Impossible')
	else:
		for i in range(n):
			print(match[i] + 1)