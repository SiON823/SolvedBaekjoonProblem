x = int(input())
lst = [64, 32, 16, 8, 4, 2, 1]
cnt = 0

for val in lst:
    if x >= val:
        cnt += 1
        x -= val
    if x == 0:
        break

print(cnt)