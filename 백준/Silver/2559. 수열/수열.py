import sys

N, K = list(map(int, input().split()))
lst = list(map(int, sys.stdin.readline().split()))

sum_lst = [0]
summary = 0
R = 0
L = 0

for i in range(N):
    summary += lst[i]
    sum_lst.append(summary)

m = -987654321

for i in range(1, N - K + 2):
    L = i
    R = L + K - 1
    if m < sum_lst[R] - sum_lst[L - 1]:
        m = sum_lst[R] - sum_lst[L - 1]

print(m)