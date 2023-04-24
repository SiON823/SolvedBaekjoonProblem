aaaa = "aeiouAEIOU"

while True:
    x = input()
    if x == "#":
        break
    cnt = 0
    for i in range(len(x)):
        if x[i] in aaaa:
            cnt += 1
    print(cnt)