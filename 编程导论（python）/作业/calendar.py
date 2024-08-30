def isLeap(n):
    if not n%100:
        return n%400 == 0
    return n%4 == 0
    
def weekdayCount(n):
    cnt = [0 for i in range(7)]
    cur = 0
    for i in range(n):
        for j in range(12):
            cnt[(cur+13)%7-1] += 1
            if j+1 in [4, 6, 9, 11]:
                cur += 30
            elif j+1 in [1, 3, 5, 7, 8, 10, 12]:
                cur += 31
            elif isLeap(1900+i):
                cur += 29
            else:
                cur += 28
    return cnt

for n in [1, 5, 12, 300]:
    print(n, weekdayCount(n))
