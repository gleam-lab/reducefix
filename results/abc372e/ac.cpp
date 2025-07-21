#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,sum,cnt,fa[N],a[N];
set<int>s[N];
set<int>::iterator it;
int find(int x)
{
	if(fa[x]==x)
		return x;
	else
		return fa[x]=find(fa[x]);
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int i,j,x,y,z,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		fa[i]=i,s[i].insert(i);
	for(i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
		{
			x=find(x),y=find(y);
			if(s[x].size()>s[y].size())
				swap(x,y);
			fa[x]=y,s[y].insert(s[x].begin(),s[x].end());
			while(s[y].size()>10)
				s[y].erase(s[y].begin());
		}
		else
		{
			x=find(x);
			it=s[x].begin();
			if(s[x].size()<y)
			{
				cout<<"-1\n";
				continue;
			}
			advance(it,s[x].size()-y);
			cout<<*it<<"\n";
		}
	}
	return 0;
}