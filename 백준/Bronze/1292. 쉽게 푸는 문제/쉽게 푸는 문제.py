a, b = map(int, input().split())
lst = []
for i in range(1, 1000):
    for j in range(i):
        lst.append(i)
a, b = a-1, b-1    
sum = 0
for i in range(a, b+1):
    sum += lst[i]

print(sum)