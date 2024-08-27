#include<bits/stdc++.h>
using namespace std;
//p3367
const int NM=10010;
int fa[NM];
int n,m;
void init()//初始化，每个人的父亲都是自己，说明都是根
{
    for(int i=0;i<n;i++)
    {
        fa[i] = i;
    }
}

int find_fa(int x)//找到父亲
{
    if(x != fa[x])
    {
        fa[x] = find_fa(fa[x]);
    }
    return fa[x];
}

void join(int x, int y)//合并操作
{
    int fa_x = find_fa(x),fa_y = find_fa(y);
    if(fa_x!=fa_y)
    {
        fa[fa_y] = fa_x;
    }
}
int main()
{
    cin>>n>>m;
    init();
    for(int _=0;_<m;_++)
    {
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1)
        {
            join(x,y);
        }else
        {
            find_fa(x) == find_fa(y)?cout<<"Y"<<endl:cout<<"N"<<endl;
        }
    }
}