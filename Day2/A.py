# 前缀和
# 预处理
# 内置函数
# from itertools import accumulate
# pre_handle=list(accumulate(map(int,input().split())))
# 手动
input()# 读取N
sum = []
ori = list(map(int,input().split()))
sum.append(ori[0])
for i in range(1,len(ori)):
    sum.append(sum[i-1] + ori[i])
'''
前缀和是将一个队列的数替换成该数与前面所有数的和
用于求多个区间和
'''
res = []
for _ in range(int(input())):
    tar = list(map(int,input().split()))
    if tar[0]-2<0:
        res.append(sum[tar[1]-1])
    else:
        res.append(sum[tar[1]-1]-sum[tar[0]-2])
print(*res,sep="\n")