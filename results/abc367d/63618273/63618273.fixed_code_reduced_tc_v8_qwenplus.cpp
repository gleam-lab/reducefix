#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
	int n,M;
	cin>>n>>M;
	vector<int>a(n+1);
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	vector<int>s(n+1);
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+a[i];
	}
	map<int, int>mp;
	ll ans=0;
	mp[0] = 1; // Important: empty prefix has sum 0
	for(int i=1; i<=n; i++){
		int remainder = s[i] % M;
		ans += mp[remainder];
		mp[remainder]++;
	}
	cout<<ans<<'\n';
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