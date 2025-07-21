#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define mod 1e9+7
#define inf INT_MAX
#define all(v) v.begin(), v.end()

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    sort(all(a));
    
    ll min_diff = LLONG_MAX;
    
    // Iterate over all possible positions to split the array into two parts
    for (int i = 0; i <= n - k - 1; ++i) {
        ll max_val = a[min(n - 1, i + k)];
        ll min_val = a[max(0, i)];
        min_diff = min(min_diff, max_val - min_val);
    }
    
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}