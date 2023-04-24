n = int(input())
data = list(map(int, input().split()))

if n == 1:
    print('A')
elif n == 2:
    print(data[0] if data[0] == data[1] else 'A')
else:
    a = (data[1] - data[2]) // (data[0] - data[1]) if data[0] != data[1] else 0
    b = data[1] - data[0] * a

    for i in range(n - 1):
        if data[i + 1] != data[i] * a + b:
            print('B')
            break
    else:
        print(data[-1] * a + b)