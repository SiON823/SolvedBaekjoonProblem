lst = [0 for _ in range(42)]

for i in range(10):
    x = int(input())
    lst[x%42]+=1

cnt = 0

for i in range(42):
    if lst[i] != 0:
        cnt+=1

print(cnt)