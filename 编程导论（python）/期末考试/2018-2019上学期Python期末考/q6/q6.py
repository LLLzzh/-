def gcd(a, b):
    if not b:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return b//gcd(a, b)*a

input()
lst = map(int, input().split())
ret = 1
for i in lst:
    ret = lcm(ret, i)
print(ret)
