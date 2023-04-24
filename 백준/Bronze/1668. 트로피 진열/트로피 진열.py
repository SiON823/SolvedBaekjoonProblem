N = int(input())
lst = []
for i in range(N):
    lst.append(int(input()))

mx = 0
cnt = 0
for i in range(N):
    if mx < lst[i]:
        cnt += 1
        mx = lst[i]

print(cnt)

mx = 0
cnt = 0
for i in reversed(range(N)):
    if mx < lst[i]:
        cnt += 1
        mx = lst[i]

print(cnt)


