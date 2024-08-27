nb_of_nums = int(input())
nums = list(map(int,input().split()))
# 初始化
zhan = list()
res = list()
# ————单调栈————
"""
因为对于每个元素的结果与其后面的元素有关，故越后的元素越易得出，故从后往前。
而且*对于当前数后比当前小的数不可能是当前数之前的数的结果*，
故维护一个存下标的栈，在每次计算一个新数时，从这个栈中找离栈顶最近的大于当前数的数
并检查栈顶元素是否大于当前数，
若是，则放入当前数，
反之则删除栈顶数并重复检查

直到计算完所有数
"""
for i in range(nb_of_nums-1,-1,-1):
    while zhan and nums[zhan[-1]]<=nums[i]:
        zhan.pop(-1)
    if not zhan:
        res.append(0)
    else:
        res.append(zhan[-1]+1)
    zhan.append(i)
res.reverse()
print(*res)