#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[2*N],d[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int i,j,x,y,z,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
	memset(b,0,sizeof(b));
	b[0]=1;
	long long ans=0;
	d[0]=0;
	for(i=1;i<2*n;i++)
	{
		d[i]=(d[i-1]+a[i])%m;
		if(d[i]<0) d[i]+=m;
		ans+=b[d[i]];
		if(i<n)
			b[d[i]]++;
	}
	cout<<ans;
	return 0;
}