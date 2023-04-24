while True:
  x = int(input())
  if x == 0: break
  sum = 1
  while x>0:
    t = x%10
    if t == 0: sum += 4
    elif t == 1: sum += 2
    else: sum += 3
    sum += 1

    x = x//10
  
  print(sum)
