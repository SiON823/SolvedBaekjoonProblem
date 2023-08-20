import sys

input = sys.stdin.readline

N, M = map(int, input().split())
DNA = list(input())
checklst = list(map(int, input().split()))
lst = [0 for _ in range(4)]
check = 0
res = 0


def add(c):
    global checklst, lst, check
    if c == 'A':
        lst[0] += 1
        if lst[0] == checklst[0]:
            check += 1
    elif c == 'C':
        lst[1] += 1
        if lst[1] == checklst[1]:
            check += 1
    elif c == 'G':
        lst[2] += 1
        if lst[2] == checklst[2]:
            check += 1
    else:
        lst[3] += 1
        if lst[3] == checklst[3]:
            check += 1


def remove(c):
    global checklst, lst, check
    if c == 'A':
        if lst[0] == checklst[0]:
            check -= 1
        lst[0] -= 1
    elif c == 'C':
        if lst[1] == checklst[1]:
            check -= 1
        lst[1] -= 1
    elif c == 'G':
        if lst[2] == checklst[2]:
            check -= 1
        lst[2] -= 1
    else:
        if lst[3] == checklst[3]:
            check -= 1
        lst[3] -= 1


for i in range(4):
    if checklst[i] == 0:
        check += 1

for i in range(M):
    add(DNA[i])

if check == 4:
    res += 1

for i in range(M, N):
    j = i - M
    add(DNA[i])
    remove(DNA[j])
    if check == 4:
        res += 1

print(res)