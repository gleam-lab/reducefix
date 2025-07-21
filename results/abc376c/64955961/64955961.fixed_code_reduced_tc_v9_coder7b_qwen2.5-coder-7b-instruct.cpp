#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n-1; ++i) cin >> b[i];

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Find the maximum gap between consecutive elements in sorted array b
    ll max_gap = 0;
    for(ll i = 1; i < n-1; ++i) {
        max_gap = max(max_gap, b[i] - b[i-1]);
    }

    // Check if the largest element in a can fit into the largest gap in b
    if(a[n-1] <= max_gap + b[n-2]) {
        cout << a[n-1] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}