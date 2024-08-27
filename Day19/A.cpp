#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=110;
int h[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&h[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(h[i]>h[1])
        {
            printf("%lld\n",i);
            return;
        }
    }
    printf("-1\n");
}
signed main()
{
    int T;
    // cin>>T;
    T=1;
    while(T--)
    {
        solve();
    }
    return 0;
}
