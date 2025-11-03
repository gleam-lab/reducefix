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
		cin>>a[i];
	
	long long ans = 0;
	map<int, int> cnt;
	cnt[0] = 1;
	int prefix = 0;
	
	for(i=1;i<=n;i++)
	{
		prefix = (prefix + a[i]) % m;
		ans += cnt[prefix];
		cnt[prefix]++;
	}
	
	cout<<ans;
	return 0;
}