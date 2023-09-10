N = int(input())
lst = [int(input()) for _ in range(N)]
lst.sort()
temp = []

for i in range(0, N):
    cnt = 0
    for j in range(lst[i], lst[i] + 5):
        if j not in lst:
            cnt += 1
    temp.append(cnt)

print(min(temp))
