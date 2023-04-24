a = int(input())
lst = [a//10, a%10]
lst = [lst[1], (lst[0]+lst[1])%10]
cnt = 1
while lst != [a//10, a%10]:
    lst = [lst[1], (lst[0]+lst[1])%10]
    cnt += 1

print(cnt)
