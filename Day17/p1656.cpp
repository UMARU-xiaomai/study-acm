#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//Tarjan算法求无向图的割边：
/*
维护了两个数组dfn和low：

dfn[now]表示节点now被访问的时间戳。
low[now]表示节点now及其子树中能够通过返祖边（Back Edge）回到祖先节点的最早时间戳。

如果存在某个节点y使得low[y] > dfn[now]，则now和y之间的边是一个桥。
*/
const int MAXN = 150;
vector<int> edge[MAXN];
int dfn[MAXN], low[MAXN], id;
vector<pair<int, int>> ans;
/*
算法步骤
初始化:

设定时间戳id从1开始，dfn和low数组初始化为0。
DFS遍历:

从任意一个未访问过的节点开始进行DFS，遍历过程中记录每个节点的dfn和low值。
对于每个节点u，对其每个邻接节点v进行处理：
如果v是u的父节点，则跳过（避免回到父节点）。
如果v已经被访问过（即dfn[v]不为0），说明v是一个后向边（可以回到已访问的祖先节点），因此更新low[u]为min(low[u], dfn[v])。
如果v还没有被访问过，继续DFS递归处理v，处理完后更新low[u]为min(low[u], low[v])。
判断割边:

在递归返回时，判断是否存在low[v] > dfn[u]。如果存在，说明无法通过子树回到u或u的祖先节点，因此边(u, v)为割边（桥）。
直观理解是，如果low[v]大于dfn[u]，说明子树中所有节点无法通过非父边到达u及以上的祖先节点，这意味着删除边(u, v)会使图分为两个不连通部分。
*/
void dfs(int now, int fa) {
    dfn[now] = low[now] = ++id;
    for (auto y : edge[now]) {
        if (y == fa) continue;  // 是父亲节点
        if (dfn[y]) {  // 访问过的点，说明是后向边
            low[now] = min(low[now], dfn[y]);
        } else {  // 没访问过
            dfs(y, now);
            low[now] = min(low[now], low[y]);
            if (low[y] > dfn[now]) {
                if (now > y) swap(now, y);//题目要求从小到大输出
                ans.push_back({now, y});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);//无向图
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) dfs(i, -1);//确保每一个点都被dfs
    }

    sort(ans.begin(), ans.end());  // 按 a 从小到大排序，如果 a 相同则按 b 从小到大排序
    for (auto& p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
