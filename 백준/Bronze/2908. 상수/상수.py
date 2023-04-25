a, b = map(int, input().split())

a = (a%10)*100 + ((a//10)%10)*10 + (a//100)*1 
b = (b%10)*100 + ((b//10)%10)*10 + (b//100)*1 

print(a) if a > b else print(b)