x = int(input())
lst = list(map(int, input().split()))
Y, M = 0, 0
for i in range(x):
    Y += 10 * (lst[i]//30 + 1)
    M += 15 * (lst[i]//60 + 1)

if Y==M: print(f"Y M {Y}")
elif Y<M: print(f"Y {Y}")
else: print(f"M {M}")