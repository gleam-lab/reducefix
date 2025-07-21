#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL<<60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i=0; i<n; i++) cin >> ab[i].first;
    for (int i=0; i<n; i++) cin >> ab[i].second;
    sort(ab.begin(), ab.end());
    if (k == 1) {
        ll ans = inf;
        for (int i=0; i<n; i++) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q; // Max-heap for storing second elements
    ll sum = 0;
    // Initially populate the max-heap with the smallest k-1 second elements
    for (int i=0; i<k-1; i++) {
        q.push({ab[i].second, ab[i].first});
        sum += ab[i].second;
    }
    ll ans = inf;
    // Iterate through the remaining elements
    for (int i=k-1; i<n; i++) {
        auto [b, a] = ab[i];
        ans = min(ans, (sum + b) * a);
        // Check if the smallest element in the heap can be replaced by the current element
        if (!q.empty() && q.top().first < b) {
            sum -= q.top().first;
            auto [next_b, next_a] = q.top();
            sum += b;
            q.pop();
            q.push({b, a});
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  cin >> t;
    while (t--) solve();
}