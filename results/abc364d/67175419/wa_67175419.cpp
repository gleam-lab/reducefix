#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,sum,cnt,a[N];
int check(int x,int y,int z)
{
	int a1=lower_bound(a+1,a+n+1,y-x)-a,b1=upper_bound(a+1,a+n+1,y+x)-a;
	return b1-a1>=z;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int i,j,x,y,z,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	while(m--)
	{
		cin>>x>>y;
		int l=0,r=1e8;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(!check(mid,x,y))
				l=mid+1;
			else
				r=mid-1;
		}
		cout<<l<<"\n";
	}
	return 0;
}