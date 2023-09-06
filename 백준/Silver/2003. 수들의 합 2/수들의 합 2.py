import sys
input = sys.stdin.readline

N, M = map(int, input().split())

lst = list(map(int, input().split()))
sum_lst = [0, lst[0]]
for i in range(2, N+1):
    sum_lst.append(sum_lst[i-1] + lst[i-1])

res = 0

for i in range(N):
    for j in range(i+1, N+1):
        if sum_lst[j] - sum_lst[i] == M:
            res += 1

print(res)
