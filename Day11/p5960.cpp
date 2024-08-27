#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 50005;
const int M = 50005;

struct edge {
    int v, w, fail;
    edge() {}
    edge(int _v, int _w, int _fail) {
        v = _v;
        w = _w;
        fail = _fail;
    }
} e[M];
int head[N], len;
void init() {
    memset(head, -1, sizeof(head));
    len = 0;
}
void add(int u, int v, int w) {
    e[len] = edge(v, w, head[u]);
    head[u] = len++;
}
/*
    容易发现，差分约束的方程和最短路中的松弛操作类似，建出图后加入一个源点与所有点连一条边权为 0 的边，进行完最短/最长路之后的 {di} 即为一组解。
	*应该最短路还是最长路
	*记得判负环/正环
	*如果约束条件为 xi-xj=k
	

 */
int n, m;
int dis[N], in[N];//in用来解决负环问题
bool vis[N];
bool spfa(int u) {
    memset(vis, false, sizeof(vis));
    vis[u] = true;
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    memset(in, 0, sizeof in);
    in[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = false;
        for (int j = head[u]; ~j; j = e[j].fail) {
            int v = e[j].v;
            int w = e[j].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    ++in[v];
                    if (in[v] > n + 1) return true;//判断负环，因为加了一个超级源点，故应跟 n + 1 而不是 n 比较。
                }
            }
        }
    }
    return false;
}

int main() {
    init();
    int u, v, w, op;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        add(u, v, -w);
    } 
    for (int i = 1; i <= n; ++i) add(0, i, 0);
    if (spfa(0)) cout << "NO" << endl;
    else for (int i = 1; i <= n; ++i) cout << dis[i] << " ";
    return 0;
}