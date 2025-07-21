#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    // The minimum possible value of the difference between the maximum and minimum of the new array
    // can be achieved by removing k smallest and k largest elements and keeping the rest
    ll ans = a[k] - a[n-k-1];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}