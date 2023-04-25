def f(n):
    if n==0:
        return 1
    res = 1
    for i in range(1, n+1):
        res *= i
    return res

N, K = map(int, input().split())
print(f(N) // (f(K) * f(N-K)))