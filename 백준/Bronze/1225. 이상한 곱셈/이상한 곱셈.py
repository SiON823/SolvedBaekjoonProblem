A, B = map(int, input().split())
A1, B1 = 0, 0

while(A > 0):
    A1 += A%10
    A=A//10
while(B > 0):
    B1 += B%10
    B=B//10
print(A1*B1)