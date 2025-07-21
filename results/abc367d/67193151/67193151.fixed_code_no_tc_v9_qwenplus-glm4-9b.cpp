#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int i, x, y, z, t;
	cin >> n >> m;
	for(i=1; i<=n; i++)
		cin >> a[i], a[i+n] = a[i]; // Extend array a to handle wrap-around
	b[0] = 1;
	for(i=1; i<n*2; i++)
	{
		// Update the count for the current position in array b
		if(i >= n)
			b[d[i-n]%m]--; // Decrement the count for the current value (if within range)
		d[i] = d[i-1] + a[i]; // Calculate the new value of d[i]
		sum += b[d[i]%m]; // Add the count from b to sum based on the new value of d[i]
		if(i < n)
			b[d[i]%m]++; // Increment the count for the current value (if within range)
	}
	cout << sum << endl;
	return 0;
}