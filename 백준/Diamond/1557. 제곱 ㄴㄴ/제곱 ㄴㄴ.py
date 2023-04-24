import math

def SFL_cnt(n):
    p = 0
    for i in range(1, int(math.sqrt(n)) + 1, 1):
        p += mobius[i] * (n // (i * i))
    return p


mobius = [0] * 1000001

k = int(input())
mobius[1] = 1

for i in range(1, 1000001):
    if mobius[i]:
        for j in range(i * 2, 1000001, i):
            mobius[j] -= mobius[i]

l, r = 0, 2000000000

while l < r - 1:
    mid = (l + r) // 2
    if SFL_cnt(mid) < k:
        l = mid
    else:
        r = mid
print(r)