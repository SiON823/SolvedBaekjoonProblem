s = input()
lst = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]

ans = 0

for i in s:
	for idx, j in enumerate(lst):
		if i in j:
			ans += idx + 3

print(ans)