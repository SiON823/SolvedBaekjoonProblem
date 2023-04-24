N = int(input())
F = int(input())

N = N//100 * 100
for i in range(100):
    if (N + i) % F == 0:
        if i<10: print(f'0{i}')
        else: print(i)
        break