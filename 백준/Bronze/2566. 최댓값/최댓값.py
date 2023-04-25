c = [[0 for _ in range(9)] for i in range(9)]

for i in range(9):
    c[i] = list(map(int, input().split()))

maxlst = [[0, 0] for i in range(9)]

for i in range(9):
    maxlst[i][0] = max(c[i])
    maxlst[i][1] = c[i].index(max(c[i]))
    
ans = 0
anscoord = [0, 0]

for i in range(9):
    ans = max(ans, maxlst[i][0])
    if ans == maxlst[i][0]:
        anscoord = [i+1, maxlst[i][1]+1]
        
print(ans)
print(*anscoord)