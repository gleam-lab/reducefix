#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;

    // Directions from which a square can be attacked
    const array<array<ll, 2>, 8> directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        occupied.emplace(a, b);
        for (const auto& d : directions) {
            ll ni = a + d[0];
            ll nj = b + d[1];
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                occupied.emplace(ni, nj);
            }
        }
    }

    // Total grid size is N*N. Subtract the number of attacked or occupied squares.
    cout << (N * N - static_cast<ll>(occupied.size())) << '\n';

    return 0;
}