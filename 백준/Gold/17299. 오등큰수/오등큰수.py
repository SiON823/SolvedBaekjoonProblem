import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

cnt = {}
sta = [0]
ans = [-1 for _ in range(N)]

cnt[0] = 0

for i in A:
    if i not in cnt.keys():
        cnt[i] = 1
    else:
        cnt[i] += 1

for i in range(N-1, -1, -1):
    while len(sta) != 0:
        if cnt[sta[-1]] <= cnt[A[i]]:
            sta.pop()
        else:
            ans[i] = sta[-1]
            break

    sta.append(A[i])


print(*ans)
