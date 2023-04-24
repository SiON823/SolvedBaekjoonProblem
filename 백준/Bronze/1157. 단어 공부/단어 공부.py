string = input()
alist = [0 for _ in range(26)]

for i in range(len(string)):
    if ord(string[i]) - ord('A') < 26:
        alist[ord(string[i]) - ord('A')] += 1
    elif ord(string[i]) - ord('a') < 26:
        alist[ord(string[i]) - ord('a')] += 1


if alist.count(max(alist)) > 1:
    print('?')
else:
    print(chr(alist.index(max(alist))+ord('A')))