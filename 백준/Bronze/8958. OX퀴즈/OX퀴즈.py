T = int(input())

for _ in range(T):
    sum = 0
    com = 0
    x = input()
    for i in x:
        
        if i=='O':
            com+=1
            sum+=com
        else:
            com=0
    print(sum)