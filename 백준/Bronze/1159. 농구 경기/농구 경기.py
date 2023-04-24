N = int(input())
lst = []
cnt = [0 for i in range(26)]

for i in range(N):
    lst.append(input()[0])

for c in lst:
    cnt[ord(c) - ord('a')] += 1

check = False

for i in range(26):
    if cnt[i] >= 5:
        check = True
        print(chr(i + ord('a')), end='')

if not check:
    print("PREDAJA")
else:
    print()
