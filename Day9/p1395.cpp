#include<bits/stdc++.h>

using namespace std;
#define MAXN 10001
vector<int> ver[MAXN];
int n,root;
int siz[MAXN],dist[MAXN],ans[MAXN];


void dfs1(int x, int fa) {//找重心
    siz[x] = 1;
    for(auto u : ver[x]) {
        if(u == fa) continue;
        dfs1(u, x);
        siz[x] += siz[u];
        ans[x] = max(ans[x], siz[u]);//找到非头顶子树中节点最多的（不含自己）
    }
    ans[x] = max(ans[x], n - siz[x]);//检查顶上那个子树（fa为root，然后切断与x联系）是不是最大的
}

void dfs2(int x, int fa) {//求距离和
    if(x != root) dist[x] = dist[fa] + 1;
    for(auto u : ver[x]) {
        if(u == fa) continue;
        dfs2(u, x);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        ver[u].push_back(v);
        ver[v].push_back(u);
    }
    dfs1(1, 0);
    root = min_element(ans + 1, ans + n + 1) - ans;//ans是指针
    cout << root << " ";
    dfs2(root, 0);
    int ans2 = accumulate(dist + 1, dist + n + 1, 0);
    cout << ans2 << "\n";
}
