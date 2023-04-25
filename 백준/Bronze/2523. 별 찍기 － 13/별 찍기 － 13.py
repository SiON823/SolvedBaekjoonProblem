N = int(input())
for i in range(1, N+1):
	for j in range(i): print("*", end="")
	print()
for i in reversed(range(1, N)):
	for j in range(i): print("*", end="")
	print()