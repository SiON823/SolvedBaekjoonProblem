import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    PS = list(input())[:-1]

    sta = []
    check = True
    for i in PS:
        if i == '(':
            sta.append(0)
        else:
            if len(sta) != 0:
                sta.pop()
            else:
                check = False
                print("NO")
                break

    if check:
        if len(sta) == 0:
            print("YES")
        else:
            print("NO")
