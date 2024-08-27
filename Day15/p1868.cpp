#include<bits/stdc++.h>
#define MAXN 3000010
using namespace std;
vector<int>y_s_x[MAXN];//表示给定y所对应的区间x,不一定只有一个，故用vector
int n,max_y,f[MAXN];//max_y 代表最大的 y，f 是 dp 数组
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		y_s_x[y].push_back(x-1);//把x加到对应的y上
		max_y=max(max_y,y);
	}
	for(int i=1;i<=max_y;i++){
		f[i]=f[i-1];//初始
		for(int j=0;j<y_s_x[i].size();j++){
			int b=y_s_x[i][j];
			f[i]=max(f[i],f[b]+i-b);//决定要不要取这个区间
		}
	}
	cout<<f[max_y]<<endl;
	return 0;
}