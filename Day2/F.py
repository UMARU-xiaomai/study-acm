n,k = list(map(int,input().split()))
chocs =[]
cur_length = 0
for i in range(n):
    chocs.append(list(map(int,input().split())))
    for j in chocs[i]:
        if j>cur_length:
            cur_length = j# 找到巧克力边长的最大值

nb_of_ch = 0
for i in chocs:
    nb_of_ch+=(i[0]//cur_length)*(i[1]//cur_length)# 第一遍

while nb_of_ch <k:# 循环减小正方形巧克力的边长直至所有小朋友都能获得巧克力
    cur_length-=1
    nb_of_ch = 0
    for i in chocs:
        nb_of_ch+=(i[0]//cur_length)*(i[1]//cur_length)
print(cur_length)