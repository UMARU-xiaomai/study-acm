#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int INF = 1e9;
int n, m;
int dist[MAXN][MAXN];

inline void Floyd() {
    for (int k = 1; k <= n; ++k) { // 允许中间经过1~k的节点
        for (int i = 1; i <= n; ++i) { // 起点
            for (int j = 1; j <= n; ++j) { // 终点
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // 初始化距离矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // 读取边的信息并初始化距离矩阵
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);  // 考虑可能有重边的情况
        dist[v][u] = min(dist[v][u], w);  // 无向图
    }

    Floyd(); // 运行Floyd-Warshall算法

    // 输出最终的最短路径矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
