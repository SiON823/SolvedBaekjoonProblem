import sys
input = sys.stdin.readline

N = int(input())

A = list(map(int, input().split()))

sta = []
ans = [0 for _ in range(N)]

for i in range(N):
    while sta and sta[-1][0] < A[i]:
        sta.pop()
    if len(sta) == 0:
        pass
    else:
        ans[i] = sta[-1][1] + 1
    sta.append((A[i], i))

print(*ans)