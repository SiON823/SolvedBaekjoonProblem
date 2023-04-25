# 5597
# 과제 안 내신 분..?

a = [0 for _ in range(31)]
for i in range(28):
    a[int(input())] = 1
for i in range(1, 31):
    if a[i] == 0:
        print(i)