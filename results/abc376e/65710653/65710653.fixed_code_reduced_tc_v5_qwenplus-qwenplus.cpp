#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

#define rep(i, a, b) for(ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for(ll i = (b)-1; i >= (a); --i)

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pll> items(N);
    for (ll i = 0; i < N; ++i) cin >> items[i].first;
    for (ll i = 0; i < N; ++i) cin >> items[i].second;

    // Sort by A_i in ascending order
    sort(items.begin(), items.end());

    // Use min-heap to keep track of the K smallest B_i values
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum_b = 0;
    
    // Initialize with first K elements
    for (ll i = 0; i < K; ++i) {
        pq.push(items[i].second);
        sum_b += items[i].second;
    }

    // Initial answer candidate
    ll ans = sum_b * items[K - 1].first;

    // Sliding window
    for (ll i = K; i < N; ++i) {
        // Remove the smallest B from the current set
        if (!pq.empty() && items[i].second > pq.top()) {
            sum_b -= pq.top();
            pq.pop();
            // Add new B value
            pq.push(items[i].second);
            sum_b += items[i].second;
        }
        // Update the answer
        ans = min(ans, sum_b * items[i].first);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}