def enc(s):
    lst = s.split(' ')
    res = ''
    for word in lst:
        tmp = ''
        for i in range(len(word)):
            if i&1:
                tmp += word[i].upper()
            else:
                tmp += word[i].lower()
        half = len(word)//2
        res += tmp[half:]+tmp[:half]+' '
    return res[:-1]

print(enc(input()))
