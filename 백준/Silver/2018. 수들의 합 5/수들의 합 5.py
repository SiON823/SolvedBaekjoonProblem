n=int(input())
cnt = 1
start = 1
end = 1
summ = 1

while end != n:
    if summ == n:
        cnt += 1
        end += 1
        summ += end
    elif summ > n:
        summ -= start
        start += 1
    else:
        end += 1
        summ += end

print(cnt)