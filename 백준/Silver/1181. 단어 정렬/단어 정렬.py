N = int(input())
l = []
for i in range(N): l.append(input().strip())
l = list(set(l))
l.sort(key=lambda x: (len(x), x))
for word in l: print(word)