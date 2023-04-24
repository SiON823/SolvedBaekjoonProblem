T = int(input())

def pow(a, b, mod):
    if b==0:
        return 1
    
    x = pow(a, b//2, mod) % mod

    if b%2 == 0:
        return x*x % mod
    else:
        return x*x*a % mod

for _ in range(T):
    a, b = map(int, input().split())
    a = a%10
    x = pow(a, b, 10)
    if x!=0: print(x)
    else: print("10")