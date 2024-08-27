# 前缀和数组：适用于查询操作频繁且更新操作较少的场景。因为查询操作是 O(1)，但更新操作需要 O(n)。
# 树状数组：适用于查询和更新操作都频繁的场景。因为查询和更新操作都可以在 O(log n) 时间内完成。
n,m = list(map(int,input().split()))
ori = list(map(int,input().split()))

class FenwickTree:
    def __init__(self, size):
        # 初始化树状数组，长度为 size + 1
        self.size = size
        self.BIT = [0] * (size + 1)

    def update(self, index, delta):
        # 更新树状数组
        i = index + 1  # 调整索引为 1-based
        while i <= self.size:
            self.BIT[i] += delta
            i += i & -i  # 移动到下一个需要更新的节点

    def query(self, index):
        # 查询前缀和
        sum = 0
        i = index + 1  # 调整索引为 1-based
        while i > 0:
            sum += self.BIT[i]
            i -= i & -i  # 移动到上一个需要查询的节点
        return sum

ft = FenwickTree(n)
for i in range(n):
    ft.update(i,ori[i])
res = []
for _ in range(m):
    op,x,y = list(map(int,input().split()))
    if op ==1:
        ft.update(x-1,y)
    else:
        res.append(ft.query(y-1)-ft.query(x-2))
print(*res,sep="\n")