N, M = map(int, input().split())

lst = [i for i in range(1, N+1)]

for _ in range(M):
    i, j, k= map(int, input().split())
    lst = lst[:i-1]+ lst[k-1:j] + lst[i-1:k-1]+lst[j:]
    
print(*lst)