#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    // Sort by A in ascending order
    sort(ab.begin(), ab.end());

    if (k == 1) {
        ll ans = INF;
        for (auto [a, b] : ab) {
            ans = min(ans, a * b);
        }
        cout << ans << '\n';
        return;
    }

    // Maintain a max-heap for the B values of the smallest K-1 elements
    priority_queue<ll> q;
    ll sum_b = 0;
    for (int i = 0; i < k - 1; ++i) {
        q.push(ab[i].second);
        sum_b += ab[i].second;
    }

    ll ans = INF;
    for (int i = k - 1; i < n; ++i) {
        auto [a, b] = ab[i];
        // Current candidate: a * (sum_b + b)
        ans = min(ans, a * (sum_b + b));

        // If we can still take more elements to maintain K-1 smallest A values
        if (i < n - 1) {
            // If current element's b is smaller than the largest in heap or heap size < k-1
            if (q.size() < k - 1 || b < q.top()) {
                if (q.size() >= k - 1) {
                    sum_b -= q.top();
                    q.pop();
                }
                q.push(b);
                sum_b += b;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}