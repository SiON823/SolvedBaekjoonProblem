import random

def power_mod(x, y, mod):
    x %= mod
    ret = 1
    while(y > 0):
        if(y%2 == 1): ret = (ret*x)%mod
        x = (x*x)%mod
        y //= 2
    return ret

def check_prime(n, a):
    if(a%n == 0): return True
    k = n-1
    while True:
        temp = power_mod(a, k, n)
        if(temp == n-1): return True
        if(k%2 == 1): return (temp == 1 or temp == n-1)
        k //= 2

def is_prime(n):
    if(n == 2 or n == 3): return True
    if(n%2 == 0): return False

    a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
    for i in range(12):
        if not check_prime(n, a[i]):
            return False
    return True

def GCD(a, b):
    if(a < b): a, b = b, a
    while(b != 0):
        r = a%b
        a = b
        b = r
    return a

def find_div(n):
    if(n%2 == 0): 
        return 2
    if(is_prime(n)): 
        return n

    x = random.randint(2, n-2)
    y, c, g = x, random.randint(1, 10), 1

    while(g == 1):
        x = (x*x%n + c)%n
        y = (y*y%n + c)%n
        y = (y*y%n + c)%n
        g = GCD(abs(x-y), n)
        if(g == n): 
            return find_div(n)
    if(is_prime(g)): 
        return g
    else: 
        return find_div(g)

N = int(input())


if(N == 1): 
    print("1")
else:
    ansList = []
    while(N > 1):
        div = find_div(N)
        ansList.append(div)
        N //= div

    ansList.sort()
    ans, mulNum = 1, 2
    for i in range(len(ansList)-1):
        if(ansList[i] == ansList[i+1]): mulNum += 1
        else: ans *= mulNum; mulNum = 2
    ans *= mulNum
    print(ans)
