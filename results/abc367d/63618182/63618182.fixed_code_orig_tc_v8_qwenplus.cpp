#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
	int n,M;
	cin>>n>>M;
	vector<int>a(n+10);
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	vector<int>s(n+10);
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+a[i];
	}
	map<int, int>mp;
	ll ans=0,L=s[n];
	mp[0] = 1; // Important: empty prefix has sum 0
	for(int i=1; i<=n; i++){
		// Count how many previous prefixes have the same remainder
		ans += mp[s[i] % M];
		// Also count prefixes where (current_sum - prev_sum) % M == L % M
		// This means: (s[i] - s[j]) % M == L % M
		// => s[j] % M == (s[i] - L % M + M) % M
		ans += mp[(s[i] - L % M + M) % M];
		mp[s[i] % M]++;
	}
	cout<<ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll t=1;
	while(t--){
		solve();
	}
	return 0;
}