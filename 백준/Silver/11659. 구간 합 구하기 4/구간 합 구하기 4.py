import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lst = list(map(int, input().split()))
sum_lst = [0]

for i in range(N):
    sum_lst.append(sum_lst[i] + lst[i])

for i in range(M):
    a, b = map(int, input().split())
    print(sum_lst[b]-sum_lst[a-1])
