import sys
sys.setrecursionlimit(10**5)

def go(x, y):
    if check[x][y] == 0:
        return
    
    check[x][y] = 0

    go(x+1, y)
    go(x-1, y)
    go(x, y+1)
    go(x, y-1)

    return


T = int(input())

for _ in range(T):
    cnt = 0
    M, N, K = map(int, input().split())
    check = [[0 for a in range(53)] for b in range(53)]
    for i in range(K):
        x, y = map(int, input().split())
        check[x][y] = 1

    for i in range(M):
        for j in range(N):
            if check[i][j] != 0:
                go(i, j)
                cnt += 1

    print(cnt)