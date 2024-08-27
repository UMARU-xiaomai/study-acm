#include<bits/stdc++.h>

using namespace std;
#define MAXN 10000
//p2842
int n,w;
int f[MAXN],a[MAXN];
int dfs(int x)
{
	if(x==0)
		return 0;
	if(f[x]!=MAXN)//如果没有计算过才计算
		return f[x];
	//查找用纸币数最少的方案
	
	for(int i  = 0;i<n;i++)
	{
		if(x-a[i]>=0)
			f[x] = min(f[x],dfs(x-a[i])+1);
	}
	
	return f[x];
}
int main()
{
    cin>>n>>w;
	for(int i = 0;i<n;i++)
	{
		
		cin>>a[i];
	}	
	for(int i = 0;i<=w;i++)// 必须初始化到w
		f[i] = MAXN;
	f[0] = 0;
	cout<<dfs(w)<<endl;
}