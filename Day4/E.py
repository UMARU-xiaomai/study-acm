r, c = list(map(int, input().split()))
city_map = []
start = []
mem = []
n = int(input())  # 读取方向数
# 读取地图并找到初始位置
for i in range(r):
    city_map.append(list(input()))
    mem.append([])
    for j in range(c):
        mem[i].append([])
        for k in range(n):
            mem[i][j].append(0)
        if city_map[i][j] == '*':
            start = [i, j]
            city_map[i][j] = '.'

directions = []
for _ in range(n):
    cur_dir = input()
    if cur_dir == 'NORTH':
        directions.append((-1, 0))
    elif cur_dir == 'SOUTH':
        directions.append((1, 0))
    elif cur_dir == 'WEST':
        directions.append((0, -1))
    elif cur_dir == 'EAST':
        directions.append((0, 1))
print(directions)
# 深度优先搜索（DFS）
def DFS(x, y, cur_direct):
    global city_map,directions,r,c,mem
    dx, dy = directions[cur_direct]
    nx, ny = x, y
    while 0 <= nx + dx and nx + dx< r and 0 <= ny + dy and ny + dy < c and city_map[nx + dx][ny + dy] != 'X':
        nx += dx
        ny += dy
        # 如果步数走完就把位置设置为*
        if cur_direct >= len(directions)-1:
            city_map[nx][ny] = '*'
    
        else:# 否则就继续搜索（深度优先）
            if mem[nx][ny][cur_direct+1]==0:
                mem[nx][ny][cur_direct+1] = 1
                DFS(nx, ny, cur_direct + 1)
        

DFS(start[0], start[1], 0)

# 输出结果地图
for row in city_map:
    print(''.join(row))
