
w, n = map(int, input().split())
objs = [int(input()) for _ in range(n)]

def DFS(cur, end, c_sum, result):
    if cur >= end:
        result.append(c_sum)
        return
    DFS(cur + 1, end, c_sum, result)
    if c_sum + objs[cur] <= w:
        DFS(cur + 1, end, c_sum + objs[cur], result)

tmp1 = []
tmp2 = []

DFS(0, n // 2, 0, tmp1)
DFS(n // 2, n, 0, tmp2)

tmp2.sort()

res = 0
for s1 in tmp1:
    if s1 > w:
        continue
    l, r = 0, len(tmp2) - 1
    while l <= r:
        mid = (l + r) // 2
        if s1 + tmp2[mid] <= w:
            res = max(res, s1 + tmp2[mid])
            l = mid + 1
        else:
            r = mid - 1

print(res)

