N, K = map(int, input().split())
cnt = 0
lst = []
for i in range(N):
	lst.append(int(input()))

while len(lst) != 0:
	x = lst[-1]
	if K < x:
		lst.remove(x)
	else:
		K -= x
		cnt += 1

print(cnt)

