#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
#define maxn 10005
#define maxm 500005
#define inf 1234567890
int n,m,s,tot,dis[maxn],head[maxn];
bool vis[maxn];
struct Edge
{
      int next,to,w;
}h[maxm];
void add(int u,int v,int w)
{
    h[++tot].next=head[u];
    h[tot].to=v;
    h[tot].w=w;
    head[u]=tot;
}
//上面和dijkstra算法基本上一样
queue<int> q;
//队列优化
//SPFA算法是处理带负权单源最短路径的方案
inline void spfa()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        //赋初值
    }
    int u,v;
    q.push(s);
    dis[s]=0;
    //将起点的值负为0
    vis[s]=1;//这句话可加可不加，因为循环的时候vis[s]又会被赋为0
    while(!q.empty())
    //当队列里没有元素的时候，那就已经更新了所有的单源最短路径
	{
        u=q.front();
        //将队手节点记录并弹出队首节点
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=h[i].next)
        //寻找与u相连的边
		{
            v=h[i].to;
            if(dis[v]>dis[u]+h[i].w)
			{
                dis[v]=dis[u]+h[i].w;
                //松弛操作，和floyd比较相似
                if(!vis[v])
				{
                //已经在队列里的点就不用再进入了
                      vis[v]=1;
                      q.push(v);
                }
            }
        }
    }
}
int main(){
    n=read(),m=read(),s=read();
    for(int i=1,u,v,w;i<=m;i++)
	{
        u=read(),v=read(),w=read();
        add(u,v,w);
    }
    spfa();
    for(int i=1; i<=n; i++)
    {
        printf("%d ",dis[i]);
    }
    return 0;
}