# ————归并排序————
n=int(input())
ori = list(map(int,input().split()))
'''
在归并的同时计算逆序对的个数
'''
nxd = 0
res = []
for _ in range(len(ori)):
    res.append(0)
def Msort(l,r):
    global res,ori,nxd # 允许函数使用全局变量
    if l==r :
        return
    mid = l+(r-l)//2
    Msort(l,mid)
    Msort(mid+1,r) # 左右均闭
    i,j,p = l,mid+1,l
    while i<=mid and j<=r:
        if ori[i]>ori[j]:
            res[p] = ori[j]
            # ori[j]与前半形成mid-i+1个逆序对
            nxd +=mid-i+1
            j+=1
        else:
            res[p] = ori[i]
            i+=1
        p+=1
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
print(nxd)
