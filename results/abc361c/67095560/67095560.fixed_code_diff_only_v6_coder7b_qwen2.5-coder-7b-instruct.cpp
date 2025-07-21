#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define vi vector<ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // Calculate the minimum possible difference
    ll min_diff = LLONG_MAX;
    for (ll i = 0; i <= n - k; ++i) {
        min_diff = min(min_diff, a[i + k - 1] - a[i]);
    }
    
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}