#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    
    // Sort A in descending order and B in ascending order
    sort(ab.begin(), ab.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    
    ll max_A = ab[k-1].first;
    ll sum_B = 0;
    for (int i = 0; i < k; i++) {
        sum_B += ab[i].second;
    }
    
    ll ans = max_A * sum_B;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}