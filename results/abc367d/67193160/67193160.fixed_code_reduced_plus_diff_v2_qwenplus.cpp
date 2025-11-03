#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int i,j,x,y,z,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
	memset(b,0,sizeof(b));
	b[0]=1;
	long long sum = 0;
	long long prefix = 0;
	for(i=1;i<=2*n-1;i++)
	{
		prefix += a[i];
		int mod = (prefix % m + m) % m;
		if(i >= n) {
			int prev_mod = (prefix - a[i-n] * 1LL - d[i-n-1]) % m;
			prev_mod = (prev_mod + m) % m;
			b[prev_mod]--;
		}
		d[i] = prefix;
		sum += b[mod];
		if(i < n)
			b[mod]++;
	}
	cout<<sum;
	return 0;
}