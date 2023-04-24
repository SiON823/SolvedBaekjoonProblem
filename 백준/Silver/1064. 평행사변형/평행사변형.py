xa, ya, xb, yb, xc, yc = map(int, input().split())

if ((xa-xb)*(ya-yc)==(ya-yb)*(xa-xc)):
    print(-1.0)
    exit(0)

ab_length = ((xa-xb)**2 + (ya-yb)**2)**0.5
ac_length = ((xa-xc)**2 + (ya-yc)**2)**0.5
bc_length = ((xb-xc)**2 + (yb-yc)**2)**0.5

length = [ab_length+ac_length, ab_length+bc_length, ac_length+bc_length]
result = max(length) - min(length)
print(2*result)