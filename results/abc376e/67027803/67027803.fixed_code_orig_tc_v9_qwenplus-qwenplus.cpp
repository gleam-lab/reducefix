#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i=0; i<n; ++i) cin >> ab[i].first;
    for (int i=0; i<n; ++i) cin >> ab[i].second;

    sort(ab.begin(), ab.end());
    
    if (k == 1) {
        ll ans = INF;
        for (auto [a, b] : ab) {
            ans = min(ans, a * b);
        }
        cout << ans << '\n';
        return;
    }

    // We will maintain a max-heap to track the smallest k-1 B values
    priority_queue<ll> pq;
    ll sum_b = 0;
    for (int i = 0; i < k - 1; ++i) {
        pq.push(-ab[i].second); // Use negative to simulate min-heap
        sum_b += ab[i].second;
    }

    ll ans = INF;
    for (int i = k - 1; i < n; ++i) {
        auto [a, b] = ab[i];
        ans = min(ans, (sum_b + b) * a);

        if (!pq.empty() && -pq.top() < b) {
            sum_b -= -pq.top();
            sum_b += b;
            pq.pop();
            pq.push(-b);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}