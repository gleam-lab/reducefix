#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
	
	long long ans = 0;
	vector<int> count(m, 0);
	count[0] = 1; // empty prefix has sum 0
	
	long long prefix_sum = 0;
	for(int i=1; i<=2*n; i++) {
		prefix_sum += a[i];
		int mod = (prefix_sum % m + m) % m; // handle negative modulo
		
		// For positions in the first half (original array), add to count
		if (i <= n) {
			ans += count[mod];
			count[mod]++;
		} 
		// For positions in the second half (duplicate), only count but don't add to frequency
		else {
			ans += count[mod];
			// Don't increment count for second half
		}
	}
	
	cout << ans;
	return 0;
}