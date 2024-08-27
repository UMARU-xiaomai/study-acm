n, k = map(int, input().split())
a = list(map(int, input().split()))

max_que = []
l,r=0,0
# ————滑动窗口/单调队列————
# 以最小值为例
'''
创建一个队列（左出-右入），
在右边界向右移动时：将右侧所有比输入数大的数删除后再放入新的数
在左边界向右移动时：检查左侧第一个目录是否仍在范围内
这就是一个单调递增的队列，最左边的数就是窗口中最小的数

（最大值同理）
'''
res = []
# 先初始化，达到窗口目标长度，此时只有右边界向右移动（窗口宽度次）
while r<k:
    while max_que and a[max_que[-1]]>a[r]:
        max_que.pop(-1)
    max_que.append(r)
    r+=1
res.append(a[max_que[0]])
l+=1
#  开始向右滑动
while r<n:
    if max_que and max_que[0]<l:
        max_que.pop(0)
    while max_que and a[max_que[-1]]>a[r]:
        max_que.pop(-1)
    max_que.append(r)
    res.append(a[max_que[0]])
    r+=1
    l+=1
print(*res)

max_que = []
l,r=0,0

res = []
while r<k:
    while max_que and a[max_que[-1]]<a[r]:
        max_que.pop(-1)
    max_que.append(r)
    r+=1
res.append(a[max_que[0]])
l+=1
while r<n:
    if max_que and max_que[0]<l:
        max_que.pop(0)
    while max_que and a[max_que[-1]]<a[r]:
        max_que.pop(-1)
    max_que.append(r)
    res.append(a[max_que[0]])
    r+=1
    l+=1
print(*res)