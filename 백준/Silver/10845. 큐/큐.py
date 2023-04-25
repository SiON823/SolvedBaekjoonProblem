n = int(input())
import sys
input = sys.stdin.readline


queue = []
for i in range(n):
    lst = input().split()

    if lst[0] == 'push':
        queue.append(lst[1])
    elif lst[0] == 'pop':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.pop(0))
    elif lst[0] == 'size':
        print(len(queue))
    elif lst[0] == 'empty':
        if len(queue) == 0:
            print(1)
        else:
            print(0)

    elif lst[0] == 'front':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])

    elif lst[0] == 'back':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
