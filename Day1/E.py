res = []
'''
————单调队列————
关键点：双指针[l,r]遍历所有底边长，但是每个底边长对应的矩形的高只能是其中最矮的，故考虑维护单调递增队列
但与之前不同的是，我们仍需要底边长度信息，故不删除，而是将队列右侧大于新加数的改成等于新加数，这样想要获取区间[l,r]中最小值时直接获取l下标对应值就可以了,
而且由于要复用，右侧不用删除
'''
while True:
    rects = list(map(int,input().split()))
    if rects[0]==0:
        break
    que = []
    max_mianji = 0
    for i in range(len(rects)):
        pt = -1
        while pt>=-len(que) and que[pt]>rects[i]:
            que[pt] = rects[i]
            pt-=1
        que.append(rects[i])
        for l in range(len(que)):
            tmp = (len(que)-l)*que[l]
            if tmp>max_mianji:
                max_mianji=tmp
    res.append(max_mianji)
print(*res,sep="\n")