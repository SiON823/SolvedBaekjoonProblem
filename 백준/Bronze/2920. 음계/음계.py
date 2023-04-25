a = list(map(int, input().split()))
x = [1,2,3,4,5,6,7,8]
y = [8,7,6,5,4,3,2,1]

if a==x:
    print("ascending")
elif a==y:
    print("descending")
else:
    print("mixed")
