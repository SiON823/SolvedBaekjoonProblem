n = int(input())
lst = list(map(int, input().split()))

av = 0

for i in range(n):
    av += (lst[i]/max(lst))*100

print(float(av)/n)