#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> prefix(n + 1, 0); // Use long long to prevent overflow
    for(int i = 0; i < n; i++) {
        prefix[i+1] = (prefix[i] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;
    
    for(ll i = 0; i <= n; i++) {
        // Count how many times this remainder has appeared before
        ans += cnt[prefix[i]];
        // Increment the count for this remainder
        cnt[prefix[i]]++;
    }
    
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}