#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define arr array<int,3>

const int N=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;

int a[N],b[N];
PII sa[N];
vector<int> e[N];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		for(int i=1;i<=n;i++)
			cin>>b[i];
			
		for(int i=1;i<=n;i++)
			sa[i]={a[i],b[i]};
		
		sort(sa+1,sa+1+n);
		
		int res=INF,sum=0;
		priority_queue<int> q; // Max-heap to store the largest B_i values
		for(int i=1;i<=n;i++)
		{
			if(i<=k-1)
			{
				sum+=sa[i].se;
				q.push(-sa[i].se); // Use negative to simulate a min-heap
				continue;
			}
			
			int na=sa[i].fi;
			sum+=sa[i].se;
			// Remove the smallest B_i from sum if the heap size is greater than k-1
			if(q.size() > k-1)
			{
				sum += q.top(); // Push the smallest B_i back to sum
				q.pop();
			}
			q.push(-sa[i].se); // Push the negative of the current B_i to maintain the min-heap
			res=min(res, na * sum);
		}
		
		cout<<res<<endl;
	}

}