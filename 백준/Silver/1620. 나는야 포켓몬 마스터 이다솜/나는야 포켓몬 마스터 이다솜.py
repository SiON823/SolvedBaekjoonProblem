import sys
input = sys.stdin.readline

n, m = list(map(int, sys.stdin.readline().split()))
lst = {}
for i in range(n):
    name = input().rstrip()
    lst[name] = i+1
    lst[str(i+1)] = name
for i in range(m):
    x = input().rstrip()
    print(lst[x])