def pow(s, e):
    ret = 1
    while s > e:
        ret *= s
        s -= 1
    return ret

def A(n, m):
    return pow(n, n-m)

m, n = map(int, input().split())
print(A(m, m-n))
