n,m = list(map(int,input().split()))
ground = []
for i in range(n+1):
    ground.append([])
    for _ in range(n+1):
        ground[i].append(0)
"""
对于每个地毯(x1, y1)到(x2, y2)，在差分数组中进行四次更新：
左上角(x1, y1)加1，表示从这里开始增加覆盖。
右下角的右下方(x2+1, y2+1)加1，表示从这里开始减去覆盖。
左下角的右方(x2+1, y1)减1，表示从这里开始停止增加覆盖。
右上角的下方(x1, y2+1)减1，表示从这里开始停止增加覆盖。
（一个格子的增减表示其右下侧的所有格子的实际值进行相同的操作）
"""
for _ in range(m):
    x,y,i,j = list(map(int,input().split()))
    ground[x-1][y-1] += 1
    ground[i][y-1] -=1
    ground[x-1][j] -=1
    ground[i][j] +=1

su = []
for i in range(n+1):
    su.append([])
    for _ in range(n+1):
        su[i].append(0)
        
for i in range(1,n+1):
    for j in range(1,n+1):
        su[i][j] += ground[i-1][j-1]+su[i-1][j]
        su[i][j] += su[i][j-1]
        su[i][j] -= su[i-1][j-1]
    print(*su[i][1:])