a = int(input())
b = int(input())
c = int(input())

x = a*b*c
lst = [0 for _ in range(10)]

while x!=0:
    lst[int(x%10)] += 1
    x=x//10

for i in range(10):
    print(lst[i])