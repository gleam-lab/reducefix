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
		cin>>a[i]; // Removed the line to expand the array, as it's not needed.
	b[0] = 1; // Initialized frequency count array within the loop scope.
	
	for(i=1;i<n*2;i++)
	{
		d[i] = d[i-1] + a[i % n]; // Improved index calculation with modulo.
		// Assuming the following logic is intended:
		if (d[i] % m <= 0) sum += b[d[i] % m]; // Check if d[i] % m is non-negative.
		if (i < n) b[d[i] % m]++; // Increment only when i is within the first n.
		if (i >= n) b[d[i] % m]--; // Decrement only when i is within the range [n, n*2).
	}
	cout<<sum;
	return 0;
}