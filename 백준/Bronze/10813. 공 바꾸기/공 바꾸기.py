N, M = map(int, input().split())

lst = [i for i in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    lst[a], lst[b] = lst[b], lst[a]

for i in lst:
    if i!=0 : print(i, end=' ')