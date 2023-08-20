from collections import deque
N, L = map(int, input().split())
Q = deque()
A = list(map(int, input().split()))

for i in range(N):
    while Q and Q[-1][0] > A[i]:
        Q.pop()
    Q.append((A[i], i))
    if Q[0][1] <= i - L:
        Q.popleft()
    print(Q[0][0], end=' ')