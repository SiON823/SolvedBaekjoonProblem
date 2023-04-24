N, L = map(int, input().split())

t = 0
x = -1
iter = 0

for i in range(L, 101):
    t = (i * i - i) / 2
    if (N - t) % i == 0 and (N - t) // i >= 0:
        x = (N - t) // i
        iter = i
        break

if x == -1: print(-1)
else: print(*range(int(x), int(x+iter)))