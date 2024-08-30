a = [
    [[10, 5], [8, 4]],
    [[20, 1]]
]

# See if two polynomial are equal
def equal(a, b):
    if len(a) != len(b):
        return False
    for i in range(len(a)):
        if a[i][0] != b[i][0] or a[i][1] != b[i][1]:
            return False
    return True

# Compress a polynomial. Combine items with the same degree and remove items with coefficient 0.
def compress(a):
    res = []
    for i in range(1, len(a)):
        if a[i][0] == a[i-1][0]:
            a[i][1] += a[i-1][1]
        elif a[i-1][1]:
            res.append(a[i-1])
    if a[-1][1]:    
        res.append(a[-1])
    return res


def poly_multiplication(a, b):
    a.sort(reverse=True)
    b.sort(reverse=True)
    
    res = []
    if not (a and b):
        return []
    for i in a:
        for j in b:
            res.append([i[0]+j[0], i[1]*j[1]])
    res.sort(reverse=True)
    return compress(res)


def poly_substraction(a, b):
    a.sort(reverse=True)
    b.sort(reverse=True)
    
    res = []
    len_a, len_b = len(a), len(b)
    i, j = 0, 0
    while i < len_a and j < len_b:
        if a[i][0] > b[j][0]:
            res.append(a[i])
            i += 1
        elif a[i][0] < b[j][0]:
            res.append([b[j][0], -b[j][1]])
            j += 1
        else:
            res.append([a[i][0], a[i][1]-b[j][1]])
            i += 1
            j += 1
    if i < len_a:
        res += a[i:]
    else:
        while j < len_b:
            res.append(b[j][0], -b[j][1])
            j += 1
    return compress(res)


def poly_addition(a, b):
    a.sort(reverse=True)
    b.sort(reverse=True)
    
    res = []
    len_a, len_b = len(a), len(b)
    i, j = 0, 0
    while i < len_a and j < len_b:
        if a[i][0] > b[j][0]:
            res.append(a[i])
            i += 1
        elif a[i][0] < b[j][0]:
            res.append(b[j])
            j += 1
        else:
            res.append([a[i][0], a[i][1]+b[j][1]])
            i += 1
            j += 1
    if i < len_a:
        res += a[i:]
    else:
        res += b[j:]
    return compress(res)


def poly_division(a, b):
    a = a[:]
    b = b[:]
    a.sort(reverse=True)
    b.sort(reverse=True)
    if b[0][0] > a[0][0]:
        return [], a
    res = []
    i = 0
    while a[0][0] >= b[0][0]:
        temp_res = [[a[i][0]-b[0][0], a[i][1]/b[0][1]]]
        res += temp_res
        a = poly_substraction(a, poly_multiplication(temp_res, b))
        if not a:
            return res, []
    res.sort(reverse=True)
    return res, a[i:]

r, t = poly_division(a[0], a[1])
print("商:", r)
print("余数:", t)

# verification
print(equal(a[0], poly_addition(t, poly_multiplication(a[1], r))))
