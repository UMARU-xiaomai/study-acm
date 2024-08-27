n,m = list(map(int,input().split()))
nums = list(map(int,input().split()))
# 初始化
nb_of_painter = 1
max_length = n
l,r=0,0
res_l,res_r = 0,n-1
painterDic = dict()
for i in nums:
    painterDic[i]=0
painterDic[nums[0]] = 1
# 关键代码
'''
————双指针————
P1638
通过l,r来维护一个队列，
字典维护队列内各个画家画的个数，
nb_of_painter表示队列中包含画家数，

每次循环时检查nb_of_painter是否包含（等于）全部画家，
若是，则左缩队；
若不是，则右增队列。
直至右边界到结束
仅对增或减的那个画进行改变
'''
while l<=r and r<n-1:
    # 满足包含全部画家
    if nb_of_painter == m:
        # 检查是不是区间更小
        if r-l<res_r-res_l:
            res_l=l
            res_r=r

        # 更新左缩的那个画，注意先处理再l++    
        painterDic[nums[l]]-=1
        if painterDic[nums[l]] == 0:
            nb_of_painter-=1
        l+=1
        
    else:
        # 更新右进的那个画
        r+=1
        painterDic[nums[r]]+=1
        if painterDic[nums[r]] == 1:
            nb_of_painter+=1
# 输出
print(f"{res_l+1} {res_r+1}")