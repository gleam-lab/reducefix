#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,sum,cnt,a[N],b[N],c[N],d[N];
bool check(int mid)
{
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cnt=INT_MAX;
		for(int j=mid/a[i]+1;j>=max(mid/a[i]-100,0ll);j--)
			cnt=min(cnt,j*c[i]+max(0ll,mid-j*a[i]+b[i]-1)/b[i]*d[i]);
		for(int j=mid/b[i]+1;j>=max(mid/b[i]-100,0ll);j--)
			cnt=min(cnt,j*d[i]+max(0ll,mid-j*b[i]+a[i]-1)/a[i]*c[i]);
		sum+=cnt;
	}
	return sum<=m;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int i,j,x,y,z,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i]>>c[i]>>b[i]>>d[i];
	int l=0,r=INT_MAX;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			k=mid,l=mid+1;
		else
			r=mid-1;
	}
	cout<<k;
	return 0;
}