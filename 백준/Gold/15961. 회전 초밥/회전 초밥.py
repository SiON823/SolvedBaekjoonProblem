import sys

input = sys.stdin.readline

N, M, K, T = map(int, input().split())
sushi = [int(input()) for _ in range(N)]

cnt, c = [0] * (M + 1), 0
for i in range(K):
    cnt[sushi[i]] += 1
    if cnt[sushi[i]] == 1: 
        c += 1

mx = c + (cnt[T] == 0)
for i in range(N):
    cnt[sushi[i]] -= 1

    if cnt[sushi[i]] == 0:
        c -= 1

    cnt[sushi[(i + K) % N]] += 1

    if cnt[sushi[(i + K) % N]] == 1:
        c += 1
    mx = max(mx, c + (cnt[T] == 0))
print(mx)
