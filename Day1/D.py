def GetSortValue(a):
    return a[0]

n,d = map(int,input().split())
drips = []
for _ in range(n):
    drips.append(list(map(int,input().split())))

drips.sort(key=GetSortValue)
l,r = 0,-1
max_que = []
min_que = []

res = n
'''
————双指针+单调队列————
通过维护一个区间[l,r]和维护两个单调队列，分别用来获取当前区域的最小和最大值
当时间差（最大-最小）满足时左缩，不满足时则右扩
队列左缩时检查俩队列左侧是否仍在区域内
右扩时将右侧所有比输入数大/小的数删除后再放入新的数
'''
# 开始向右
while r<n-1:
    if max_que and min_que and drips[max_que[0]][1]-drips[min_que[0]][1]>=d:
        tmp = abs(drips[max_que[0]][0]-drips[min_que[0]][0])
        if tmp<res:
            res = tmp
        l+=1
        if min_que[0]<l:
            min_que.pop(0)
        if max_que[0]<l:
            max_que.pop(0)
    else:
        r+=1
        while min_que and drips[min_que[-1]][1]>drips[r][1]:
            min_que.pop(-1)
        min_que.append(r)
        while max_que and drips[max_que[-1]][1]<drips[r][1]:
            max_que.pop(-1)
        max_que.append(r)

print(res)
        