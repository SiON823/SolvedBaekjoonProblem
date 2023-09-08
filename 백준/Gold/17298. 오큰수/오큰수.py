import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

sta = []
ans = [-1 for _ in range(N)]

for i in range(N):
    cur = A[i]
    while sta and sta[-1][0] < cur:
        ans[sta.pop()[1]] = cur
    sta.append((cur, i))

print(*ans)
