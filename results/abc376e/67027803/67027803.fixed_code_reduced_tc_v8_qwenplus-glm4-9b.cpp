#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    
    // Pair up the A and B values and sort by A descending, then B ascending for optimal pairing
    sort(ab.begin(), ab.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first != b.first ? a.first > b.first : a.second > b.second;
    });
    
    ll ans = LLONG_MAX;
    ll sum = 0;
    // We will iterate from the best A value down to the (k-1)th best A value
    for (int i = n - 1; i >= n - k; i--) {
        // Add the B value of the current best A to the sum
        sum += ab[i].second;
        // Calculate the product of the sum of B values and the current best A
        ans = min(ans, (sum - ab[i].second) * ab[i].first);
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}