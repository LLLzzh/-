means = [1] + [0 for i in range(50)]

def f(n):
    if n < 0:
        return 0
    if not means[n]:
        means[n] = f(n-1) + f(n-2) + f(n-3) + f(n-4)
    return means[n]

n = int(input())
for i in range(n):
    ip = int(input())
    print(f(ip))
