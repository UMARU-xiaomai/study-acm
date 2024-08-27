n = int(input())
'''
————二维前缀和————
若以0，0为原点，右、下为正方向，
每个点的数据表示该点与其左上方区域所有值的和
0→→→→→→→→→→→→→→→→→→→→→→→→→→
↓##########^^^^^^^^^^^^^^·
↓##########^^^^^^^^^^^^^^·
↓#########+^^^^^^^^^^^^^-·
↓%%%%%%%%%%$$$$$$$$$$$$$$·
↓%%%%%%%%%%$$$$$$$$$$$$$$·
↓%%%%%%%%%-$$$$$$$$$$$$$+·
↓·························
'''
# 空二维数组的创建
tmp = []
rect = []
for i in range(n+1):
    rect.append([])
    for _ in range(n+1):
        rect[i].append(0)


# 预处理（可以让实际数据从（1，1）开始来减少困扰）
for i in range(1,n+1):
    ori = list(map(int,input().split()))
    for j in range(1,n+1):
        rect[i][j] = ori[j-1]+rect[i-1][j]
        rect[i][j] += rect[i][j-1]
        rect[i][j] -= rect[i-1][j-1]

# 检查矩阵
# for i in rect:
#     print(*i)
res = -1
for i in range(n+1):# 不要从1开始！！
    for j in range(n+1):
        for x in range(i,n+1):
            for y in range(j,n+1):
                tmp = rect[x][y]-rect[x][j]-rect[i][y]+rect[i][j]
                if tmp >res:
                    res = tmp
print(res)
