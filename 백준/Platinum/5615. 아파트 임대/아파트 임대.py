import sys

lst = [2,13,23,1662803]
input = sys.stdin.readline

# Miller-Rabin 코드 참조
def power(x,y,p):
    if y<2: 
        return (x**y)%p
    else:
        d = y//2

        if y%2 == 0: 
            return (power(x,d,p)**2)%p 
        else: 
            return (x*(power(x,d,p))**2)%p

def miller_rabin(n,a):
    r,d = 0,n-1

    while d%2 == 0: 
        r += 1
        d //= 2

    x = power(a,d,n)

    if x == 1 or x+1 == n: 
        return True
    
    for i in range(0, r-1):
        x = power(x,2,n)
        if x+1 == n: 
            return True
    return False

def isprime(n):
    if n in lst: 
        return True
    
    if n == 1 or n%2 == 0: 
        return False
    
    for p in lst:
        if not miller_rabin(n,p): 
            return False
        
    return True
    
cnt = 0
for _ in range(int(input())):
    if isprime(1+2*int(input())): 
        cnt += 1

print(cnt)