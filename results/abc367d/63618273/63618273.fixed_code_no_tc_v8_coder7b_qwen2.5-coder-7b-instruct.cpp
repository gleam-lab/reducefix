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
		s[i]=s[i-1]+a[i]; // Corrected s[i+1] to s[i]
	}
	map<ll, int>mp; // Changed map<int, int> to map<ll, int> for large values of s[i]
	ll ans=0,L=s[n];
	for(int i=0; i<n; i++){ // Changed i from 1 to 0 to match array index starting from 0
		ans+=(mp[(L-s[i])%M + M] % mod); // Corrected mp[(s[i]- L%M + M) % M] to mp[(L-s[i])%M + M]
		mp[s[i]%M]++;
	}
	cout<<(ans%mod);
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