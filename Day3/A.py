# ————归并排序————
n=int(input())
ori = list(map(int,input().split()))
'''
归并运用了递归的思想
'''
res = []
for _ in range(len(ori)):
    res.append(0)
def Msort(l,r):
    global res,ori # 允许函数使用全局变量
    if l==r :
        return
    mid = l+(r-l)//2
    Msort(l,mid)
    Msort(mid+1,r) # 左右均闭
    i,j,p = l,mid+1,l
    # 取两者最小
    while i<=mid and j<=r:
        if ori[i]>ori[j]:
            res[p] = ori[j]
            j+=1
        else:
            res[p] = ori[i]
            i+=1
        p+=1
    # 把剩下的数移过去
    while i<=mid:
        res[p] = ori[i]
        i+=1
        p+=1
    while j<=r:
        res[p] = ori[j]
        j+=1
        p+=1
    for i in range(l,r+1):
        ori[i] = res[i]
Msort(0,n-1)
print(*ori)
