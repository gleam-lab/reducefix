#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    
    // Sort the array to easily find min and max after removal
    sort(a.begin(), a.end());
    
    // The best strategy is to always remove the smallest and largest elements alternately
    // This way we minimize the difference between the max and min values in the resulting array
    
    ll ans = LLONG_MAX;
    for(int i = 0; i <= k; i++) {
        // Calculate the difference after removing i smallest and k-i largest elements
        ll diff = a[k - i] - a[i];
        ans = min(ans, diff);
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}