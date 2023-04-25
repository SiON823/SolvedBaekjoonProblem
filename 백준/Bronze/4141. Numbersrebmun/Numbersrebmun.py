import sys

N = int(input())
out = []

for tc in range(N):
    s = input().strip().upper()
    for i in range(len(s)):
        ch = s[i]
        if ch <= 'C':
            s = s[:i] + '2' + s[i+1:]
        elif ch <= 'F':
            s = s[:i] + '3' + s[i+1:]
        elif ch <= 'I':
            s = s[:i] + '4' + s[i+1:]
        elif ch <= 'L':
            s = s[:i] + '5' + s[i+1:]
        elif ch <= 'O':
            s = s[:i] + '6' + s[i+1:]
        elif ch <= 'S':
            s = s[:i] + '7' + s[i+1:]
        elif ch <= 'V':
            s = s[:i] + '8' + s[i+1:]
        else:
            s = s[:i] + '9' + s[i+1:]

    if s == s[::-1]:
        out.append("YES")
    else:
        out.append("NO")

print('\n'.join(out))