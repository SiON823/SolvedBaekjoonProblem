lst = [True for i in range(10001)]
for i in range(2, 10000+1):
	if lst[i]:
		x = i*2
		while x < 10001:
			lst[x] = False
			x += i
lst[1] = False
cnt = 0
N = int(input())
k = list(map(int, input().split()))
for i in range(N):
	if lst[k[i]]:
		cnt+=1
print(cnt)