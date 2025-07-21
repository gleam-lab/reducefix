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
	for(i=1;i<=n;i++)
		a[i+n]=a[i]; // Initialize the second half of array a with the first half
	b[0]=1; // Initialize the prefix sum count array b with 1 for the sum 0
	for(i=1;i<2*n;i++) // Iterate from 1 to 2*n-1 (since we are using 1-based indexing)
	{
		if(i>=n)
			b[d[i-n]]--; // Decrement the count of the previous prefix sum modulo m
		d[i]=(d[i-1]+a[i])%m; // Calculate the current prefix sum modulo m
		sum+=b[d[i]]; // Add the count of the current prefix sum modulo m to the total sum
		if(i<n)
			b[d[i]]++; // Increment the count of the current prefix sum modulo m
	}
	cout<<sum;
	return 0;
}