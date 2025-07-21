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
	{
		cin>>a[i];
		a[i+n] = a[i]; // Extend array to handle wrap-around
	}
	b[0] = n; // Initialize b[0] with n because first n elements are all the same
	for(i=1;i<=2*n;i++)
	{
		if(i < n)
			b[d[i-n]%m]++; // Increment count for the first n elements
		if(i >= n)
			b[d[i-n]%m]--; // Decrement count after the first n elements
		d[i] = d[i-1] + a[i]; // Accumulate sum
		sum += b[d[i]%m]; // Add the count of current prefix sum modulo m
	}
	cout << sum;
	return 0;
}