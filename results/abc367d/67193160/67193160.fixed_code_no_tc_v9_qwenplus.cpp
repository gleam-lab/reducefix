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
	
	sum = 0;
	b[0] = 1; // Count of prefix sums with remainder 0
	
	long long prefix = 0;
	for(i=1;i<=n;i++)
	{
		prefix += a[i];
		int rem = ((prefix % m) + m) % m; // Handle negative modulo
		sum += b[rem];
		b[rem]++;
	}
	
	cout<<sum;
	return 0;
}