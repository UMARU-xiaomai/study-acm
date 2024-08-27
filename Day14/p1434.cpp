#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
#define MAXN2 100010
int r,c;
//方向函数
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int maps[MAXN][MAXN];
int dp[MAXN][MAXN];
int dfs(int x,int y)
{
	if(dp[x][y]!=0)
		return dp[x][y];
	//否则开始计算
	dp[x][y]=1;//线路包含自己（即节点数而不是路线数）
	for(int i=0;i<4;i++)
    {  int xx=dx[i]+x;
       int yy=dy[i]+y;//四个方向
       if(xx>=0&&yy>=0&&xx<r&&yy<c&&maps[x][y]>maps[xx][yy]){
       	  dfs(xx,yy);
          dp[x][y]=max(dp[x][y],dp[xx][yy]+1);
       }

    }
	return dp[x][y];
}
int main()
{
	cin>>r>>c;
	for(int i = 0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>maps[i][j];
		}
	}
	

	int ans =0;
	for(int i = 0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			ans = max(ans,dfs(i,j));
		}
	}
	cout<<ans;
}