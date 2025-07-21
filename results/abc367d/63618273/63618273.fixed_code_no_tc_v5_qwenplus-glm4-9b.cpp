#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10, mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+10), s(n+10);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Precompute the prefix sums
    s[1] = a[1];
    for(int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    
    map<int, int> mp;
    ll ans = 0, L = s[n];
    
    // Calculate the number of valid pairs (i, j) where i < j
    for(int i = 1; i <= n; i++) {
        // Adjust the prefix sum to be within the modulo range
        int adjustedSum = (s[i] - L + mod) % mod;
        ans += mp[adjustedSum];
        mp[s[i] % mod]++;
    }
    
    cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}