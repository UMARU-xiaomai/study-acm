#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge {
    int to;   // 目标节点
    int weight; // 边的权重
};

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;

vector<Edge> graph[MAXN];  // 图的邻接表表示
int d[MAXN];               // 最短距离数组
bool visited[MAXN];        // 访问标记数组
int n, m, s;               // 点的数量，边的数量，起点

void dijkstra(int s) {
    memset(d, 0x3f, sizeof(d));  // 初始化距离数组为无穷大
    memset(visited, false, sizeof(visited));  // 初始化访问标记数组为false
    d[s] = 0;  // 起点到自己的距离为0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));  // 将起点加入优先队列，first是距离，second是节点编号
    
    while (!q.empty()) {
        int x = q.top().second;  // 取出当前距离最小的节点
        q.pop();
        
        if (visited[x]) continue;  // 如果该节点已经处理过，跳过
        visited[x] = true;  // 标记该节点已访问
        
        for (const auto& edge : graph[x]) {  // 遍历所有与节点 x 相连的边
            int y = edge.to;
            int w = edge.weight;
            
            if (d[y] > d[x] + w) {  // 如果通过 x 到 y 的距离更短
                d[y] = d[x] + w;  // 更新 y 的最短距离
                q.push(make_pair(d[y], y));  // 将更新后的节点加入优先队列
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge{v, w});  // 将边加入图中
    }
    
    dijkstra(s);  // 运行Dijkstra算法
    
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";  // 输出从起点到每个节点的最短距离
    }
    
    return 0;
}
