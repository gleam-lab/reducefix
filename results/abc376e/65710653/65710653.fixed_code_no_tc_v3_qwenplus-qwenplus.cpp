#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define fi first
#define se second
#define pb push_back

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pll> pairs(N);
    for (ll i = 0; i < N; ++i) cin >> pairs[i].fi;
    for (ll i = 0; i < N; ++i) cin >> pairs[i].se;

    // Sort by A_i ascending
    sort(pairs.begin(), pairs.end());

    // Use a multiset to maintain the K largest B_i values
    multiset<ll> b_values;
    ll sum_b = 0;

    // Initialize with first K elements
    for (ll i = 0; i < K; ++i) {
        b_values.insert(pairs[i].se);
        sum_b += pairs[i].se;
    }

    ll result = sum_b * pairs[K - 1].fi;

    // Try each possible window of K elements
    for (ll i = K; i < N; ++i) {
        // If current B is larger than smallest in set, replace it
        if (pairs[i].se > *b_values.begin()) {
            sum_b -= *b_values.begin();
            b_values.erase(b_values.begin());
            b_values.insert(pairs[i].se);
            sum_b += pairs[i].se;
        }
        result = min(result, sum_b * pairs[i].fi);
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}