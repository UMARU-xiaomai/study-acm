#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 20010;
vector<int> edge[MAXN];
int dfn[MAXN], low[MAXN], id;
set<int> cutPoints;
int rootChildren; // 存储每轮dfs后根节点的子节点数量
int root;
//有一个测试点错
void dfs(int now, int fa) {
    dfn[now] = low[now] = ++id;
    for (auto y : edge[now]) {
        if (!dfn[y]) { // 如果没有访问过
            if (fa == root) rootChildren++; // 根节点处理，统计子节点数量
            dfs(y, now);
            low[now] = min(low[now], low[y]);
            
            // 割点判定条件
            if (now != root && low[y] >= dfn[now]) {
                cutPoints.insert(now); // 记录割点
            }
        } else if (y != fa) { // 如果是回边（不是父节点的边）
            low[now] = min(low[now], dfn[y]);
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
        edge[b].push_back(a); // 无向图
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            root = i;
            rootChildren = 0;
            dfs(i, -1);
            // 如果根节点有两个或以上子树，则根节点也是割点
            if (rootChildren > 1) {
                cutPoints.insert(root);
            }
        }
    }

    cout << cutPoints.size() << endl;
    for (auto& p : cutPoints) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
