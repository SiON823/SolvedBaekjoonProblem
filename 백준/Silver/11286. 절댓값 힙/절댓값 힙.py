from queue import PriorityQueue
import sys
print = sys.stdout.write
input = sys.stdin.readline

N = int(input())
Q = PriorityQueue()

for i in range(N):
    x = int(input())
    if x == 0:
        if Q.empty():
            print('0\n')
        else:
            temp = Q.get()
            print(str((temp[1]))+'\n')
    else:
        Q.put((abs(x), x))