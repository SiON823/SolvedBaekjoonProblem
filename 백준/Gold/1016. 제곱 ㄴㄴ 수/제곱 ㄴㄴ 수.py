import math

a, b = map(int, input().split())
num = [True] * (b-a+1)

for i in range(2,int(math.sqrt(b))+1):
    temp = i*i
    while temp <= b:
        for j in range(int(a/temp) * temp , b+1 , temp):
            if j < a:
                continue
            if num[j-a]:
                num[j-a] = False
        temp*=i

print(num.count(True))