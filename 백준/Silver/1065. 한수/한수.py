# 1065
# 한수

n = int(input())
cnt = 0
for i in range(1, n+1):
    if i < 100:
        cnt += 1
    else:
        a = list(map(int, str(i)))
        if a[0]-a[1] == a[1]-a[2]:
            cnt += 1
print(cnt)