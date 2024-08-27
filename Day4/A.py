import math
n,k = list(map(int,input().split()))
nbs = list(map(int,input().split()))
def is_zhishu(t):
    if t <= 1:
        # 1和0都不是质数
        return False
    for i in range(2, t):
        if t % i == 0:
            # 整除就是余数为0 只要有一个被整除 就找到因数 就不是质数
            return False
    return True
res = 0
def DFS(i,count,sums):
    global n,k,res,nbs
    if n-i<k-count:# 剪枝：剩下的数已经无法满足所需数的数量
        return
    if count ==k:
        if is_zhishu(sums):
            res+=1
        return
    if i == n:# 取到最后一个点
        return
    # 每一个节点的下方都有两条路：选他和不选他
    DFS(i+1,count,sums)
    DFS(i+1,count+1,sums+nbs[i])
DFS(0,0,0)
print(res)