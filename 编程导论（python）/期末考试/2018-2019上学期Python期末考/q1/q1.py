def f(n):
    n = sum(int(i) for i in n)
    if 0 <= n < 10:
        return n**2+n**0.5+1
    return f(str(n))

print('%.6f'%f(input()))
