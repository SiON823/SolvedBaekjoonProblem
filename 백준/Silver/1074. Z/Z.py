N, R, C = map(int, input().split())

ans = 0

while N != 0:
    N -= 1
    if R < 2 ** N and C < 2 ** N:
        ans += (2 ** N) * (2 ** N) * 0

    elif R < 2 ** N and C >= 2 ** N:
        ans += (2 ** N) * (2 ** N) * 1
        C -= (2 ** N)

    elif R >= 2 ** N and C < 2 ** N:
        ans += (2 ** N) * (2 ** N) * 2
        R -= (2 ** N)

    else:
        ans += (2 ** N) * (2 ** N) * 3
        R -= (2 ** N)
        C -= (2 ** N)

print(ans)