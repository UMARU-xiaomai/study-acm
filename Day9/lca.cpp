#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001
int d[MAXN],f[MAXN][MAXN],tmx = 20;
vector<int> ver[MAXN];
/*
f[MAXN][MAXM]：一个二维数组，其中 f[x][i] 表示节点 x 的第 2^i 个祖先节点。
d[MAXN]：数组，表示节点 x 在树中的深度。
tmx：定义为20，表示倍增的层数，即树的深度范围。一般选择 tmx 的值是 log2(MAXN)。
ver[MAXN]：邻接表，存储树的边。
*/
//最近公共祖先（Lowest Common Ancestor, LCA）算法。LCA 是树中两个节点之间最深的公共祖先节点。
void dfs(int x, int fa) {//使用了类似于st表的倍增思想,先构建
    d[x] = d[fa] + 1;
    f[x][0] = fa;
    for(int i = 1; i <= tmx; i++) {
        f[x][i] = f[f[x][i-1]][i-1];//节点 x 的第 2^i 个祖先等于其第 2^(i-1) 个祖先的第 2^(i-1) 个祖先。
    }
    for(auto u : ver[x]) {
        if(u == fa) continue;
        dfs(u, x);
    }
}

int lca(int x, int y)
{
    if(d[x] > d[y]) swap(x, y);
    for(int i = tmx; i >= 0; i--)
    {
        if(d[f[y][i]] >= d[x]) y = f[y][i];
    }
    //通过向上跳跃节点 y 直到它的深度与 x 相同。这里的 for 循环是从最大步长开始逐步减少，使得跳跃尽可能少。

    if(x == y) return x;
    for(int i = tmx; i >= 0; i--)
    {
        if(f[x][i] != f[y][i])
        {
            x = f[x][i]; 
            y = f[y][i];
        }
    }


    return f[x][0];

}