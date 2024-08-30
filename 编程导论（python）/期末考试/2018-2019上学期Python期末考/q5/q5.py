def f(cur):
    if 0 in cur:
        i = 0
        while cur[i]:
            i += 1
        for a in range(1, 10):
            if a not in cur:
                cur[i] = a
                f(cur[:])
    else:
        l1, l2, l3 = cur[0]+cur[1]+cur[2], cur[3]+cur[4]+cur[5], cur[6]+cur[7]+cur[8]
        c1, c2, c3 = cur[0]+cur[3]+cur[6], cur[1]+cur[4]+cur[7], cur[2]+cur[5]+cur[8]
        if l1 == l2 and l2 == l3 and c1 == c2 and c2 == c3 and c1 == l1:
            print(cur[0], cur[1], cur[2])
            print(cur[3], cur[4], cur[5])
            print(cur[6], cur[7], cur[8])

lst = []
for i in range(3):
    lst += map(int, input().split())
f(lst)
