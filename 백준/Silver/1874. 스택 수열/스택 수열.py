N = int(input())
A = []

for i in range(N):
    A.append(int(input()))

sta = []
num = 1
ans = ""

for i in range(N):
    cur = A[i]
    if cur >= num:
        while cur >= num:
            sta.append(num)
            num+=1
            ans += "+\n"
        sta.pop()
        ans += "-\n"
    else:
        n = sta.pop()
        if n > cur:
            print("NO")
            exit(0)
        else:
            ans += "-\n"

print(ans)
