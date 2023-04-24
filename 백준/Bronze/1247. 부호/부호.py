for _ in range(3):
    x = int(input())
    sum = 0
    for i in range(x):
        sum += int(input())

    if sum > 0: print("+")
    elif sum == 0 : print("0")
    else: print("-")