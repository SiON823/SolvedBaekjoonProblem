mod = 1234567891
r = 31
lst = [i for i in range(1, 26+1)]

N = int(input())
s = input()
ans = 0
for i in range(N):
    ans +=  lst[ord(s[i])-ord('a')]* (r**i)

print(ans)