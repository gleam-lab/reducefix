#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    sort(ab.rbegin(), ab.rend()); // Sort in descending order based on A_i
    if (k == 1) {
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, static_cast<ll>(ab[i].first) * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }
    priority_queue<int> pq;
    ll sum = 0;
    for (int i = 0; i < k; i++) { // Change loop condition to include k elements
        pq.push(ab[i].second);
        sum += ab[i].second;
    }
    ll ans = inf;
    for (int i = k; i < n; i++) {
        auto [a, b] = ab[i];
        ans = min(ans, (sum + b) * a);
        if (pq.top() > b) {
            sum -= pq.top();
            sum += b;
            pq.pop();
            pq.push(b);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}