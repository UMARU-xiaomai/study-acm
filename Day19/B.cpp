#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> groups(0);
int res =0;
int main()
{
    cin>>n>>k;
    
    for(int i = 0;i<n;i++)
    {
		int tmp;
        cin>>tmp;
		groups.push_back(tmp);
    }
	
	int now = k;
	while(!groups.empty())
	{
		if(groups[0]<=now)
		{
			now -= groups[0];
			groups.erase(groups.begin());
			
		}else
		{
			res++;
			now =k;
		}
	}
	if(now!=k)
	{
		res++;
	}
	cout<<res;
	return 0;
}