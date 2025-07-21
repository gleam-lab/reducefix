#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

// Hash function for pair<ll, ll> to be used in unordered_set
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) * 92837149 + hash<T2>{}(p.second);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    unordered_set<pll, pair_hash> attacked;
    vector<pll> pieces(M);

    for (int i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
    }

    // Add all attacked positions to the set
    for (auto [x, y] : pieces) {
        // Row
        for (ll j = 1; j <= N; ++j)
            attacked.insert({x, j});
        // Column
        for (ll i = 1; i <= N; ++i)
            attacked.insert({i, y});
        // Diagonal 1: x - y = const
        {
            ll d = x - y;
            ll start = max(1LL, d + 1), end = min(N, N + d);
            for (ll i = start; i <= end; ++i)
                attacked.insert({i, i - d});
        }
        // Diagonal 2: x + y = const
        {
            ll s = x + y;
            ll start = max(1LL, s - N), end = min(N, s - 1);
            for (ll i = start; i <= end; ++i)
                attacked.insert({i, s - i});
        }
    }

    // Count how many of those are within bounds and actually exist
    ll totalAttacked = 0;
    for (auto [x, y] : attacked) {
        if (1 <= x && x <= N && 1 <= y && y <= N)
            ++totalAttacked;
    }

    // Total empty squares minus attacked ones
    ll totalSquares = N * N;
    cout << max(0LL, totalSquares - totalAttacked) << '\n';

    return 0;
}