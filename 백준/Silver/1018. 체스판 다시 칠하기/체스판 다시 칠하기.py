n, m = map(int, input().split())
board = []
results = []

for _ in range(n):
    board.append(input())

for i in range(n - 7):
    for j in range(m - 7):
        count1 = 0
        count2 = 0

        for a in range(i, i + 8):
            for b in range(j, j + 8):
                if (a + b) % 2 == 0:
                    if board[a][b] == 'W':
                        count1 += 1
                    else:
                        count2 += 1
                else:
                    if board[a][b] == 'W':
                        count2 += 1
                    else:
                        count1 += 1

        results.append(count1)
        results.append(count2)

print(min(results))
