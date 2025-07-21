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
		cin>>a[i],a[i+n]=a[i]; // Extend array a to handle wrap-around
	b[0]=1;
	for(i=1;i<=n*2;i++)
	{
		d[i]=d[i-1]+a[i]; // Update prefix sum array
		sum+=b[d[i]%m]; // Add the number of times the prefix sum % m has appeared

		// Update the count of prefix sums before and after i
		if (i >= n) {
			b[d[i-n]%m]--;
		}
		if (i < n) {
			b[d[i]%m]++;
		}
	}
	cout<<sum; // Output the result
	return 0;
}