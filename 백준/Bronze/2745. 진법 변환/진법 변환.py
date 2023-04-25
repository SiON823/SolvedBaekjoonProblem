N, B = input().split()
N = ''.join(reversed(N))
B = int(B)

number = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

res = 0

for x in range(len(N)-1, -1, -1):
	s = number.index(N[x]) * (B**x)
	res += s

print(res)