lst = [-1 for _ in range(26)]
x = input()

for i, s in enumerate(x):
    if lst[ord(s)-ord('a')] == -1:
        lst[ord(s)-ord('a')]=i

for i in lst:
    print(i, end=" ")