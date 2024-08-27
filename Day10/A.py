n,d = list(map(int,input().split()))
roads = []
mem = []
ans = 0
for _ in range(n+1):
    roads.append([])
    mem.append(False)
for _ in range(n-1):
    u,v = list(map(int,input().split()))
    roads[u].append(v)
    roads[v].append(u)
def dfs(now,cur_dis):
    global roads,mem,n,d,ans
    mem[now] = True
    if cur_dis>=d:
        return
    
    for i in roads[now]:
        if not mem[i]:
            dfs(i,cur_dis+1)
            ans+=1
            
dfs(1,0)
print(ans)