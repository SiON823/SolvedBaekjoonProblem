cnt=0

for i in range(8):
    lst = input()
    for j in range(8):
        if (i+j)%2 == 0 and lst[j] == 'F':
            cnt+=1

print(cnt)