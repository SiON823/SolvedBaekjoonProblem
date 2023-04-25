# 10811
# 바구니 뒤집기

n, m = map(int, input().split())
a = [i for i in range(n+1)]
for i in range(m):
    i, j = map(int, input().split())
    a[i:j+1] = a[i:j+1][::-1]
for i in range(1, n+1):
    print(a[i], end=" ")
    