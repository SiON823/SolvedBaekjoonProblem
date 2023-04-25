def stars(n):
  if n == 1:
    return ['*']

  s = stars(n//3)
  l = []

  for star in s:
    l.append(star*3)
  for star in s:
    l.append(star + ' '*(n//3) + star)
  for star in s:
    l.append(star*3)

  return l

N = int(input())
print('\n'.join(stars(N)))
