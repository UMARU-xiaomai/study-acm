import math

class ST:
    def __init__(self, array):
        self.n = len(array)
        self.k = math.floor(math.log2(self.n)) + 1
        self.st = [[0] * self.k for _ in range(self.n)]
        self.log = [0] * (self.n + 1)

        for i in range(2, self.n + 1):
            self.log[i] = self.log[i // 2] + 1

        for i in range(self.n):
            self.st[i][0] = array[i]

        for j in range(1, self.k):
            for i in range(self.n - (1 << j) + 1):
                self.st[i][j] = min(self.st[i][j - 1], self.st[i + (1 << (j - 1))][j - 1])

    def query(self, l, r):
        j = self.log[r - l + 1]
        return min(self.st[l][j], self.st[r - (1 << j) + 1][j])

n,m = list(map(int,input().split()))
st = ST(list(map(int,input().split())))
res = []
for _ in range(m):
    l,r = list(map(int,input().split()))
    res.append(st.query(l,r))
print(*res,sep="\n")
