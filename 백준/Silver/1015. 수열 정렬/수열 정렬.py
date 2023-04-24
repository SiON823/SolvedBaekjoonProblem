N = int(input())

lst = [0 for i in range(N)]
lst2 = list(map(int, input().split()))

for i in range(len(lst2)):
    min = 1001
    minidx = 0
    for idx, j in enumerate(lst2):
        if j < min:
            min = j
            minidx = idx
            
    lst[minidx] = i
    lst2[minidx] = 1001

print(*lst)
