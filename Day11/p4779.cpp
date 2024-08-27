#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;

int head[MAXN], ver[MAXN], nxt[MAXN], edge[MAXN], tot;
int d[MAXN], v[MAXN];
priority_queue<pair<int, int>> q;
int n, m, s;
/*
struct edge
{

    int value
}
*/
void add(int u, int v, int w) {
    ver[++tot] = v, edge[tot] = w, nxt[tot] = head[u], head[u] = tot;
    /*
    head[]: 记录每个节点的第一条边在 ver[] 和 edge[] 数组中的位置 节点索引->边（起点）索引头（第一条）。
ver[]: 记录每条边指向的目标节点。
nxt[]: 将同一个节点的多条边串联在一起，实现链表的效果,边索引->下一条边（同节点）。。
edge[]: 记录每条边的权重。
tot: 记录当前边的总数，用于给 ver[]、nxt[] 和 edge[] 分配位置（随着增长表示边索引）。
    */
}

inline void dijkstra() {
    memset(d, 0x3f, sizeof(d)); // 初始化距离数组d，0x3f3f3f3f表示一个很大的数
    memset(v, 0, sizeof(v));    // 初始化访问标记数组v，记录节点是否已被处理
    d[s] = 0;                   // 起点s到自己的距离为0
    q.push(make_pair(0, s));    // 将起点s放入优先队列，优先队列的元素为pair，first是距离，second是顶点编号
    
    while (q.size()) {
        int x = q.top().second; // 取出当前距离最小的节点
        q.pop();
        
        if (v[x]) continue; // 如果该节点已经被访问过，跳过
        v[x] = 1;           // 标记该节点已访问
        
        for (int i = head[x]; i; i = nxt[i]) { // 遍历从x出发的所有边
            int y = ver[i], z = edge[i];       // y是目标节点，z是边的权重
            
            if (d[y] > d[x] + z) {             // 如果通过x到y的距离小于当前记录的y的最短距离
                d[y] = d[x] + z;               // 更新y的最短距离
                q.push(make_pair(-d[y], y));   // 将y及其最短距离放入优先队列（负号表示最小堆）
            }
        }
    }
}


int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    
    dijkstra();
    
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    
    return 0;
}
