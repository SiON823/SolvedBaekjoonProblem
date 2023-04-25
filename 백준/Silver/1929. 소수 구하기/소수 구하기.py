lst = [1 for i in range(1000001)]

lst[0], lst[1] = 0, 0

for i in range(2, 1000000 + 1):
    if lst[i] == 1:
        j = 2*i
        while j < 1000001:
            lst[j] = 0
            j += i

M, N = map(int, input().split())

for i in range(M, N+1):
    if lst[i] == 1: print(i)