#include<bits/stdc++.h>
using namespace std;
#define int long long
#define arr array<int,2>

const int N=2e5+10,INF=0x3f3f3f3f;

int a[N],b[N];
arr sa[N];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		for(int i=0;i<n;i++)
			cin>>a[i];
		
		for(int i=0;i<n;i++)
			cin>>b[i];
			
		for(int i=0;i<n;i++)
			sa[i]={{a[i],b[i]}};
		
		sort(sa,sa+n);
		
		int res=INF,sum=0;
		for(int i=0;i<n;i++)
		{
			sum += sa[i][1];
			if(i >= k-1)
			{
				res = min(res, sa[i][0] * (sum - (k-1) * sa[i][1]));
			}
		}
		
		cout<<res<<endl;
	}

}