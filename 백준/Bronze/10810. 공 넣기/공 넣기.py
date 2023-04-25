N, M = map(int, input().split())

lst = [0 for i in range(N+1)]

for i in range(M):
    x, y, z = map(int, input().split())
    for j in range(x, y+1):
        lst[j] = z
        
for i in range(1,N+1):
    print(lst[i], end=" ")