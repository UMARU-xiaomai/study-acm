n = int(input())
happiness = []
for i in range(n):
    happiness.append(int(input()))

adj = [[] for _ in range(n)]
for _ in range(n - 1):
    l, k = map(int, input().split())
    adj[k - 1].append(l - 1)

dp = [[-1, -1] for _ in range(n)]

def DFS(i):
    if dp[i][0] != -1 and dp[i][1] != -1:
        return dp[i]
    
    # 不参加宴会的情况
    not_go = 0
    for v in adj[i]:
        child_dp = DFS(v)
        not_go += max(child_dp[0], child_dp[1])

    # 参加宴会的情况
    go = happiness[i]
    for v in adj[i]:
        child_dp = DFS(v)
        go += child_dp[0]
    
    dp[i][0] = not_go
    dp[i][1] = go
    return dp[i]

root = 0
for i in range(n):
    if i not in [l for sublist in adj for l in sublist]:  # 查找根节点
        root = i
        break

DFS(root)
max_happiness = max(dp[root][0], dp[root][1])
print(max_happiness)
