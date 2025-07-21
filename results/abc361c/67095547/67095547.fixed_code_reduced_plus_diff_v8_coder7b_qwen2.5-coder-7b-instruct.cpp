#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    
    // The optimal strategy is to remove the smallest k elements and the largest k elements.
    // This way, we minimize the difference between the maximum and minimum values of the remaining elements.
    ll ans = a[n-k-1] - a[k];
    
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}