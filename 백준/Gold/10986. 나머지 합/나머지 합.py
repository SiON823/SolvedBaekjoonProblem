import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lst = list(map(int, input().split()))
sum_lst = [0]

for i in range(N):
    sum_lst.append((sum_lst[i] + lst[i]))

for i in range(1, N+1):
    sum_lst[i] %= M

num_cnt = [0 for i in range(M)]

for i in range(1, N+1):
    num_cnt[sum_lst[i]] += 1

res = num_cnt[0]

for i in range(M):
    x = num_cnt[i]
    if x > 1:
        res += x * (x-1) // 2

print(res)