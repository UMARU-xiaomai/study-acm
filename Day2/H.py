# 二维离散化
'''
一维再加一层离散化，同样还是扫描线：
每个矩形左边是起点，右边是终点，要存：x、上边界、下边界、起/终
加的这一层与一维不同，由于要算面积，故不能单单使用一个数来记录，这里用了一个列表的列表cur_rectSides
是可以包含多个[l,r]的列表，表示当前延申的起始边。
对边们按照x排序后，每获取一边：
若为起点：把上下边界加到cur_rectSides，若不为第一个边，矩形面积加（当前边x-上一个边的x）*离散化cur_rectSides的结果
若为终点：在cur_rectSides查找并移除边，同样矩形面积加（当前边x-上一个边的x）*离散化cur_rectSides的结果

'''
def GetSortKey(a):
    return a[0]

# 这里复制了E的一维离散化算法，输入多个区间，输出实际覆盖范围
def LiSanHua(liOfSides):
    point = []
    for i in liOfSides:
        l,r = i
        point.append([l,0])
        point.append([r,1])
    point.sort(key=GetSortKey)
    cur_lp = 0
    last_start = 0
    res = 0
    for i in range(len(point)):
        if point[i][1] == 0:
            cur_lp +=1
            if cur_lp == 1:
                last_start = point[i][0]
        else:
            cur_lp -=1
            if cur_lp == 0:
                res += point[i][0] - last_start
    return res
            
limits = []
for _ in range(int(input())):
    tmp = list(map(int,input().split()))
    limits.append([tmp[0],tmp[3],tmp[1],0])# 分别表示x、上边界、下边界、起/终
    limits.append([tmp[2],tmp[3],tmp[1],1])

limits.sort(key=GetSortKey)
measure = 0
cur_limit = 0
# 栏杆的上下是通过两个队列来进行维护的，每次添加时加在
cur_rect_leftX=0
cur_rectSides=[]
for i in limits:
    if i[3]==0:
        cur_limit+=1
        if cur_limit ==1:
            cur_rectSides.append(i[1:3])
            cur_rect_leftX = i[0]
        else:
            measure += (i[0]-cur_rect_leftX)*LiSanHua(cur_rectSides)
            cur_rectSides.append(i[1:3])
            cur_rect_leftX = i[0]
    else:
        cur_limit-=1
        measure += (i[0]-cur_rect_leftX)*LiSanHua(cur_rectSides)
        cur_rectSides.remove(i[1:3])
        cur_rect_leftX = i[0]
print(measure)