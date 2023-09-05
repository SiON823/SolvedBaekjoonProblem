import sys
print = sys.stdout.write
A = list(input())

A.sort(reverse=True)
for x in A:
    print(x)