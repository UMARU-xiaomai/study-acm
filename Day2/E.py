def GetSortKey(a):
    return a[0]   
n=int(input())
point=[]
'''
————离散化————
对于每个起点、终点，二维数组第一位为x，第二位使用0、1来表示起终，然后放在一起按照x排序。
由于对于每队起终一定是从左到右，故从左到右一次一次获取点，使用一个整数记录获取到的起点的数量：获取到起点加一，获取到终点则减一。
只要这个数不为零，就说明是被覆盖的；如果取到终点为零了，就说明覆盖结束了，获取这个值从0到1的那个起点，俩一减就是该段实际覆盖区域
有一点像扫描线
'''
for _ in range(n):
    l,r = list(map(int,input().split()))
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
print(res)
            