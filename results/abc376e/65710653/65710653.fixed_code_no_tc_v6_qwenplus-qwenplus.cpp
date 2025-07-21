#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

#define rep(i, a, b) for(ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for(ll i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)

inline void scan() {}
template<class Head, class... Tail>
inline void scan(Head& head, Tail&... tail) {
    cin >> head;
    scan(tail...);
}

void solve() {
    ll N, K;
    scan(N, K);
    vector<pll> items(N);
    for (auto& [a, b] : items) cin >> a;
    for (auto& [a, b] : items) cin >> b;

    // Sort by A_i ascending
    sort(items.begin(), items.end());

    // Use a multiset to maintain the K largest B_i values
    multiset<ll> selected_b;
    ll sum_b = 0;

    // Initialize with first K elements
    for (ll i = 0; i < K; ++i) {
        selected_b.insert(items[i].second);
        sum_b += items[i].second;
    }

    ll ans = sum_b * items[K - 1].first;

    // Try each possible window of size K
    for (ll i = K; i < N; ++i) {
        // Remove the largest current B value
        sum_b -= *prev(selected_b.end());
        selected_b.erase(prev(selected_b.end()));

        // Add new element
        selected_b.insert(items[i].second);
        sum_b += items[i].second;

        // Update answer
        ans = min(ans, sum_b * items[i].first);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}