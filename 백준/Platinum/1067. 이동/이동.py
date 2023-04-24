from cmath import exp, pi

def fft(a):
    n = len(a)
    if n == 1:
        return a
    a_even = fft(a[0::2])
    a_odd = fft(a[1::2])
    w_n = [exp(2j * pi * k / n) for k in range(n // 2)]
    return [a_even[k] + w_n[k] * a_odd[k] for k in range(n // 2)] + [a_even[k] - w_n[k] * a_odd[k] for k in range(n // 2)]

def ifft(a):
    n = len(a)
    if n == 1:
        return a
    a_even = ifft(a[0::2])
    a_odd = ifft(a[1::2])
    w_n = [exp(-2j * pi * k / n) for k in range(n // 2)]
    return [a_even[k] + w_n[k] * a_odd[k] for k in range(n // 2)] + [a_even[k] - w_n[k] * a_odd[k] for k in range(n // 2)]

m = int(input())
n = 2 * m
even = 0
for i in range(18):
    if m == 2 ** i:
        even = -100
        break
    elif n < 2 ** i:
        even = i
        break

a = list(map(int, input().split()))
b = list(map(int, input().split()))

if even == -100:
    a = a[:] + a[:]
    b = b[-1::-1] + [0] * m
    c = [0] * n
    a_fft = fft(a)
    b_fft = fft(b)
    for i in range(n):
        c[i] = a_fft[i] * b_fft[i]

    c_ifft = ifft(c)
    for k in range(n):
        c_ifft[k] = round(c_ifft[k].real / n)
    max_number = max(c_ifft)
else:
    n_prime = 2 ** i
    n, n_prime = n_prime, n
    a = a[:] + [0] * (n - n_prime // 2)
    b = b[-1::-1] + [0] * (n - n_prime) + b[-1::-1]

    c = [0] * n
    a_fft = fft(a)
    b_fft = fft(b)
    for i in range(n):
        c[i] = a_fft[i] * b_fft[i]
    c_ifft = ifft(c)
    for k in range(n):
        c_ifft[k] = round(c_ifft[k].real / n)
    max_number = max(c_ifft)

print(max_number)