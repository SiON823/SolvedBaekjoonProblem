def check(x, y, lst):
    for i in range(N):
        if lst[i][y] == 1:
            return 0
    for i in range(M):
        if lst[x][i] == 1:
            return 0
    return 1

def check2(x, lst):
    for i in range(N):
        if lst[i][x] == 1:
            return 0
    return 1

def check3(x, lst):
    for i in range(M):
        if lst[x][i] == 1:
            return 0
    return 1

N, M = map(int, input().split())
s = [input() for i in range(N)]
lst = [[0 for i in range(M)] for i in range(N)]
ans = 0

for i in range(N):
    for j in range(M):
        if s[i][j] == ".":
            lst[i][j] = 0
        else:
            lst[i][j] = 1

for i in range(N):
    for j in range(M):
        if check(i, j, lst) == 1:
            ans += 1
            lst[i][j] = 1

for i in range(N):
    if check3(i, lst) == 1:
        lst[i][0] = 1
        ans += 1

for i in range(M):
    if check2(i, lst) == 1:
        lst[0][i] = 1
        ans += 1

print(ans)
