import sys
input = sys.stdin.readline

N = int(input())
A = []

for i in range(1, N+1):
    A.append([int(input()), i])

sA = sorted(A)
res = 0

for i in range(N):
    if res <= sA[i][1]-i:
        res = sA[i][1]-i

print(res)
