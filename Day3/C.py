# ————归并排序————
n=int(input())
ori1 = list(map(int,input().split()))
ori2 = list(map(int,input().split()))
'''
归并运用了递归的思想

1、由于火柴是一对一的，假定一列有序，将另一列排成有序即可
2、排序不等式
3、问题就转化为，只能相邻交换，求把一个序列改成有序最小需要的操作次数。
结论：序列中逆序对的个数就是需要操作的次数。（这是一个有用的结论，要记住）

'''

res1 = []
res2 = []
for _ in range(n):
    res1.append(0)
    res2.append(0)
def Msort(l,r):
    global res1,res2,ori1,ori2 # 允许函数使用全局变量
    if l==r :
        return
    mid = l+(r-l)//2
    Msort(l,mid)
    Msort(mid+1,r) # 左右均闭
    i,j,p = l,mid+1,l
    while i<=mid and j<=r:
        if ori1[i]>ori1[j]:
            res1[p] = ori1[j]
            res2[p] = ori2[j]

            j+=1
        else:
            res1[p] = ori1[i]
            res2[p] = ori2[i]
            i+=1
        p+=1
    while i<=mid:
        res1[p] = ori1[i]
        res2[p] = ori2[i]
        i+=1
        p+=1
    while j<=r:
        res1[p] = ori1[j]
        res2[p] = ori2[j]
        j+=1
        p+=1
    for i in range(l,r+1):
        ori1[i] = res1[i]
        ori2[i] = res2[i]

Msort(0,n-1)

nxd = 0
for i in range(n):
    res2[i]=0
def FindNxd(l,r):
    global res2,ori2,nxd # 允许函数使用全局变量
    if l==r :
        return
    mid = l+(r-l)//2
    FindNxd(l,mid)
    FindNxd(mid+1,r) # 左右均闭
    i,j,p = l,mid+1,l
    while i<=mid and j<=r:
        if ori2[i]>ori2[j]:
            res2[p] = ori2[j]
            nxd +=mid-i+1
            j+=1
        else:
            res2[p] = ori2[i]
            i+=1
        p+=1
    while i<=mid:
        res2[p] = ori2[i]
        i+=1
        p+=1
    while j<=r:
        res2[p] = ori2[j]
        j+=1
        p+=1
    for i in range(l,r+1):
        ori2[i] = res2[i]
FindNxd(0,n-1)
print(int(nxd%(10e8-3)))