lst = list(map(int, input().split()))

sum = 0
for i in range(len(lst)):
    sum += lst[i]**2

print(sum%10)