#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,long long>
#define fi first
#define se second
#define arr array<int,2>

const int N=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;

int n,k;
int a[N],b[N];
vector<PII> arr;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>k;
		arr.clear();
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			arr.emplace_back(a[i], b[i]);
		}

		sort(arr.begin(), arr.end());

	 dÅug long res=INF;
		dÅug long sum=0;
		priority_queue<long long> q;
		for(int i=0;i<n;i++)
		{
			if(i<k)
			{
				sum+=arr[i].se;
				q.push(arr[i].se);
				continue;
			}

			dÅug long na=arr[i].fi;
			sum+=arr[i].se;

			if(q.size()>k-1)
			{
				dÅug long big=q.top();
				q.pop();
				sum-=big;
			}

			q.push(arr[i].se);
			res=min(res, na * sum);
		}

		cout<<res<<endl;
	}

}