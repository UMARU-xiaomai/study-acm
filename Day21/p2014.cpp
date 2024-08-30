#include<bits/stdc++.h>
using namespace std;
#define MAXN 303
struct Lesson
{
    int credit;

    vector<int> son_lessons;
};

Lesson lessons[MAXN];
int n,m;
int dp[MAXN][MAXN];
void dfs(int root)
{
    cout<<root<<endl;
    // if(dp[root][1] != 0)
    // {
    //     return;
    // }
    dp[root][1] = lessons[root].credit;
    if(!lessons[root].son_lessons.empty())
    {
        for(auto i:lessons[root].son_lessons)
        {
            cout<<"son:"<<i<<endl;
            dfs(i);
            for(int a= 2;a<=m;a++)
                for(int k = 1;k<a;k++)
                    dp[root][a] = max(dp[root][a],dp[root][a-k] + dp[i][k]);
                
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        int k,s;
        cin>>k>>s;
        lessons[k].son_lessons.push_back(i);
        lessons[i].credit = s;
    }
    dfs(0);
    cout<<dp[0][m]<<endl;
}