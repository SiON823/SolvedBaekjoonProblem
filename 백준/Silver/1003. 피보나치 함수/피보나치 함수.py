T = int(input())

for _ in range(T):
    x = int(input())
    a, b = 1, 0
    for i in range(x):
        a, b = b, a+b
    print(a, b)
