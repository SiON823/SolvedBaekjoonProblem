import random

def Power(x, y, mod): # ret = (x^y)%mod
    x %= mod
    ret = 1
    while y > 0:
        if y % 2 == 1:
            ret = (ret*x) % mod
        x = (x*x) % mod
        y //= 2
    return ret

def checkPrime(n, a):
    if a % n == 0:
        return True
    k = n-1
    while True:
        temp = Power(a, k, n)
        if temp == n-1:
            return True
        if k % 2 == 1:
            return temp == 1 or temp == n-1
        k //= 2

def isPrime(n):
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False
    a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
    for i in range(12):
        if not checkPrime(n, a[i]):
            return False
    return True

def GCD(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

def findDiv(n):
    if n % 2 == 0:
        return 2
    if isPrime(n):
        return n
    x = random.randint(2, n-1)
    y = x
    c = random.randint(1, 10)
    g = 1
    while g == 1:
        x = (x*x % n + c) % n
        y = (y*y % n + c) % n
        y = (y*y % n + c) % n
        g = GCD(abs(x-y), n)
        if g == n:
            return findDiv(n)
    if isPrime(g):
        return g
    else:
        return findDiv(g)

N = int(input())
temp = N
if N == 1:
    print("1")
    exit()

List = []
while N > 1:
    div = findDiv(N)
    List.append(div)
    N //= div
List.sort()

Ans = temp
Ans //= List[0]
Ans *= (List[0]-1)
for i in range(1, len(List)):
    if List[i] != List[i-1]:
        Ans //= List[i]
        Ans *= (List[i]-1)
print(Ans)
