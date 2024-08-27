n,p = list(map(int,input().split()))
starts = list(map(int,input().split()))
starts.append(0)
'''
————差分————
即为前缀和的逆运算，表示当前数与前一数的差
用于输入是区间改变（同时对区间内的值进行相同的增减）
'''
# 差分预处理
scores = []
for _ in range(n+1):
    scores.append(0)

scores[0] = starts[0]
for i in range(1,n+1):
    scores[i] = starts[i]-starts[i-1]
del starts
# print(scores)
for _ in range(p):
    ori = list(map(int,input().split()))
    scores[ori[0]-1] +=ori[2]
    scores[ori[1]] -=ori[2]

cur = 0
res = scores[0]
for i in range(len(scores)-1):
    cur += scores[i]
    if cur<res:
        res = cur
print(res)
