n,m,s = list(map(int,input().split()))
ores = []
avg_W = 0
for _ in range(n):
    tmp = list(map(int,input().split()))
    avg_W+=tmp[0]
    ores.append(tmp)
avg_W = avg_W//n
sections = []

for _ in range(n):
    sections.append(list(map(int,input().split())))



pos=0