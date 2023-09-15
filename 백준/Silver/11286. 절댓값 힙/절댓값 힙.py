from heapq import heappush, heappop
import sys

print = sys.stdout.write
input = sys.stdin.readline

N = int(input())
Q = []

for i in range(N):
    x = int(input())
    if x == 0:
        if not Q:
            print('0\n')
        else:
            temp = heappop(Q)
            print(str((temp[1]))+'\n')
    else:
        heappush(Q,(abs(x), x))