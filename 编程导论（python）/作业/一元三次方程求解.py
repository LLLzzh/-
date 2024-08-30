tri_a = [[1, 1, 1], [2, 2, 2], [6, 0, 12]] # 三个方程组中x, y, z的系数
tri_c = [1, 2, 0]
temp = [] # 用来暂存系数的数组

infinite = True
no_solution = False
solution = [None, None, None]

for i in range(len(tri_a)):
    if not (tri_a[i][0] or tri_a[i][1] or tri_a[i][2]) and tri_c[i]:
            no_solution = True
    
for i in range(len(tri_a)):
    if tri_a[i][2] != 0:
        tri_a[0], tri_a[i] = tri_a[i], tri_a[0]
        tri_c[0], tri_c[i] = tri_c[i], tri_c[0]
        infinite = False
        break

if not infinite and not no_solution:
    # 消除z的系数
    for i in range(len(tri_a)):
        temp.append(tri_a[i][:])
        for j in range(len(tri_a[i])):
            temp[i][j] *= tri_a[0][2]
        tri_c[i] *= tri_a[0][2]
    tri_a = temp
    # print(tri_a)
    # print(tri_c)


    dual_a = []
    dual_c = []
    for i in range(1, len(tri_a)):
        temp = []
        for j in range(len(tri_a[i])):
            temp.append(tri_a[i][j]-tri_a[0][j]*tri_a[i][2]/tri_a[0][2])
        dual_a.append(temp)
        dual_c.append(tri_c[i]-tri_c[0]*tri_a[i][2]/tri_a[0][2])
    temp = []
    # print(dual_a)
    # print(dual_c)

    # 然后这就变成了一个解一元二次方程组问题. 先判断是否无解或者有无限解
    for i in range(len(dual_a)):
        if dual_a[i][0] == dual_a[i][1] and not dual_a[i][0]:
            if not dual_c[i]:
                infinite = True
            else:
                no_solution = True
            break

    for i in range(2):
        if dual_a[0][i] == dual_a[1][i] and not dual_a[0][i]:
            if not dual_c[i]:
                infinite = True
            else:
                no_solution = True
                

    if not infinite and not no_solution:
        if dual_a[1][1]:
            dual_a[0], dual_a[1] = dual_a[1], dual_a[0]
            dual_c[0], dual_c[1] = dual_c[1], dual_c[0]

        # 消除y的参数
        single_a = dual_a[0][0]*dual_a[1][1]/dual_a[0][1] - dual_a[1][0]
        single_c = dual_c[0]*dual_a[1][1]/dual_a[0][1] - dual_c[1]
        # print(single_a)
        # print(single_c)

        if not single_a and not single_c:
            infinite = True
        elif not single_a:
            no_solution = True
        else:
            solution[0] = single_c / single_a
            solution[1] = (dual_c[0]-solution[0]*dual_a[0][0]) / dual_a[0][1]
            solution[2] = (tri_c[0]-solution[0]*tri_a[0][0]-solution[1]*tri_a[0][1]) / tri_a[0][2]

if infinite:
    print("有无穷解")
elif no_solution:
    print("无解")
else:
    print("x=%f, y=%f, z=%f"%(solution[0], solution[1], solution[2]))
