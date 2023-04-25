import sys

primelst = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]
primelst2 = [ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

def pow(a,b,m):
    res = 1
    while b > 0:
        if b % 2 != 0:
            res = (res * a) % m
        b //= 2
        a = (a * a) % m
    return res

def miller_rabin(n,a):
    r = 0
    d = n-1
    while (d%2 == 0):
        r += 1
        d = d // 2
    x = pow(a,d,n)
    if x == 1 or x == n-1:
        return True
    for i in range(0,r-1):
        x = pow(x,2,n)
        if x == n-1:
            return True
    return False

def check_prime(k):
    check = 0
    if k <= 71:
        if k in primelst:
            return True
        else:
            return False
    else:
        for i in primelst2:
            if miller_rabin(k,i) == False:
                break
            else:
                check += 1
        if check == 12:
            return True
        else:
            return False



def gcd(a, b):
    if b > a:
        temp = a
        a = b
        b = temp
    while b != 0:
        r = a % b
        a = b
        b = r   
    return a

def g(x,n):
    return ((x*x) + 1) % n


def pollards_rho(n,x):
    p = x
    if check_prime(n):
        return n
    else:
        for i in primelst:
            if n % i == 0:
                return i
        y = x
        d = 1
        while d == 1:
            x = g(x,n)
            y = g(g(y,n),n)
            d = gcd(abs(x-y),n)
        if d == n:
            return pollards_rho(n,p+1)
        else:
            if check_prime(d):
                return d
            else:
                return pollards_rho(d,2)


n = int(sys.stdin.readline())
ans = []

while n != 1:
    k = pollards_rho(n,2)
    ans.append(int(k))
    n = n // k
ans.sort()

for i in ans:
    print(i)