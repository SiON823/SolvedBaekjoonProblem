L = int(input())
S = list(map(int, input().split()))
N = int(input())

S.append(0)
S.sort()

A = 0
for i in range(len(S)-1):
    if S[i] == N or S[i+1] == N:
        A = 0
        break
    elif S[i] < N < S[i+1]:
        A = (N - S[i]) * (S[i+1] - N) - 1
        break

print(A)