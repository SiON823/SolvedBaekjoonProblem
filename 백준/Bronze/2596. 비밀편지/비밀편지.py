n = int(input())
s = input()
s_li = []
for i in range(0, n * 6, 6):
    s_li.append(s[i: i + 6])

lst = ['000000', '001111', '010011', '011100', '100110', '101001', '110101', '111010']

cor = ''
inc = 0

for i in s_li:
    inc = 0
    for j in lst:
        cnt = 0
        for k in range(6):
            if i[k] == j[k]:
                cnt += 1
        if cnt >= 5:
            cor += chr(lst.index(j) + 65)
            break
        else:
            inc += 1
            
    if inc == len(lst):
        print(s_li.index(i) + 1)
        exit()
        
print(cor)