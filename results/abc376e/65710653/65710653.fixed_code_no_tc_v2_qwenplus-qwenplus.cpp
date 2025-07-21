#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sort_by_second(v) sort((v).begin(), (v).end(), [](const pll& a, const pll& b){ return a.second > b.second; })

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pll> pairs(N);
    for (ll i = 0; i < N; ++i) cin >> pairs[i].first;
    for (ll i = 0; i < N; ++i) cin >> pairs[i].second;

    // Sort by A_i in ascending order
    sort(pairs.begin(), pairs.end());

    multiset<ll> b_values;
    ll sum_b = 0;

    // Initialize with the first K elements
    for (ll i = 0; i < K; ++i) {
        b_values.insert(pairs[i].second);
        sum_b += pairs[i].second;
    }

    ll result = sum_b * pairs[K - 1].first;

    // Try to improve result using rest of the elements
    for (ll i = K; i < N; ++i) {
        if (pairs[i].second > *b_values.begin()) { // if current B is larger than max in set
            sum_b -= *b_values.begin();
            b_values.erase(b_values.begin());
            b_values.insert(pairs[i].second);
            sum_b += pairs[i].second;
            result = min(result, sum_b * pairs[i].first);
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}