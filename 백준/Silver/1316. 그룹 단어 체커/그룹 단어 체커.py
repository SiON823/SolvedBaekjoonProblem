N = int(input())

cnt = 0

for i in range(N):
    group = [0 for i in range(26)]
    word = input()
    
    for idx, j in enumerate(word):
        if group[ord(j)-97] <= 1 and (idx == 0 or j != word[idx-1]): 
               group[ord(j)-97] += 1
    
    if group.count(2) == 0:
        cnt += 1

print(cnt)