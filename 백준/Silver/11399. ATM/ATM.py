# 11399
# ATM

n = int(input())
a = list(map(int, input().split()))
a.sort()
result = 0
for i in range(n):
    result += sum(a[:i+1])
print(result)
