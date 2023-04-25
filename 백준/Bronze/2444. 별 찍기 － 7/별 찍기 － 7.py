x = int(input())

for i in range(x):
    for j in range(x-1-i):
        print(" ", end="")
    for j in range(2*i+1):
        print("*", end="")
    print()
    
for i in range(1,x):
    for j in range(i):
        print(" ", end="")
    for j in range(2*(x-1-i)+1):
        print("*", end="")
    print()