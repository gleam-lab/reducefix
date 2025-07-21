#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,k,a[N],dis[N];

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int i,j,x,y;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	while(q--)
	{
		cin>>x>>k;
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(abs(a[mid]-x)<abs(a[mid+1]-x))
				r=mid;
			else
				l=mid+1;
		}
		cout<<abs(a[l]-x)<<"\n";
	}
	return 0;
}