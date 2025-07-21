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
	
	// Calculate prefix sums and prefix sums modulo M
	vector<int> prefix(N+1);
	for(int i = 1; i <= n; i++) {
		prefix[i] = (prefix[i-1] + a[i]) % M;
	}
	
	// Use a hashmap to count occurrences of each prefix sum modulo M
	unordered_map<int, int> count_mod;
 ll ans = 0;
 
 for(int i = 1; i <= n; i++) {
	 // Calculate the complement modulo M that we need to add
	 int complement = (prefix[i] + M - L) % M;
	 ans += count_mod[complement];
	 count_mod[prefix[i]]++;
 }
 
 cout << ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}