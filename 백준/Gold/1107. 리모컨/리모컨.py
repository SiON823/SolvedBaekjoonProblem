N = int(input())
M = int(input())
remote = {str(x) for x in range(10)}

if M != 0:
    remote -= set(input().split())

cnt = abs(100 - N)

for k in range(1000000):
    num = str(k)
    x = len(num)
    for i in range(x):
        if num[i] not in remote:
            break
        if i == x - 1:
            cnt = min(cnt, abs(N - k) + x)

print(cnt)
