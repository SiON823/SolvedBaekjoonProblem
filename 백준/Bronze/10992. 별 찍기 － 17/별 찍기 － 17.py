# 10992
# 별 찍기 - 17

n = int(input())
for i in range(1, n+1):
    if i == 1:
        print(" "*(n-i), end="")
        print("*")
    elif i == n:
        print("*"*(2*i-1))
    else:
        print(" "*(n-i), end="")
        print("*", end="")
        print(" "*(2*i-3), end="")
        print("*")