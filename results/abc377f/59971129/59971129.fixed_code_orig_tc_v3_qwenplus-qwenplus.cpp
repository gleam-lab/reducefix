#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

set<ll> row_set, col_set;
set<pll> blocked;
map<ll, set<ll>> diag1_map, diag2_map;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        row_set.insert(a);
        col_set.insert(b);
        diag1_map[a - b].insert(a);
        diag2_map[a + b].insert(a);
        blocked.insert({a, b});
    }

    // Total squares not in any attacked row or column
    ll total_safe = (N - (ll)row_set.size()) * (N - (ll)col_set.size());

    // Now subtract the number of blocked squares on diagonals that are actually attackable
    auto process_diag1 = [&](ll d) {
        ll cnt = N - abs(d);
        set<ll> visited;

        if (diag1_map.count(d)) {
            for (ll r : diag1_map[d]) {
                if (col_set.count(r - d)) continue;
                if (!blocked.count({r, r - d})) {
                    cnt--;
                }
            }
        }

        return cnt;
    };

    auto process_diag2 = [&](ll s) {
        ll cnt = N - abs(s - 2 * N);
        if (s < N + 1 || s > 2 * N) {
            cnt = s <= N ? s - 1 : 2 * N - s + 1;
        }

        for (ll r : row_set) {
            ll c = s - r;
            if (c >= 1 && c <= N && !blocked.count({r, c})) {
                cnt--;
            }
        }

        for (ll c : col_set) {
            ll r = s - c;
            if (r >= 1 && r <= N && !blocked.count({r, c})) {
                cnt--;
            }
        }

        return cnt;
    };

    set<ll> diag1_vals, diag2_vals;

    for (auto [d, _] : diag1_map) diag1_vals.insert(d);
    for (auto [s, _] : diag2_map) diag2_vals.insert(s);

    for (ll d : diag1_vals) {
        total_safe -= process_diag1(d);
    }

    for (ll s : diag2_vals) {
        total_safe -= process_diag2(s);
    }

    cout << max(0LL, total_safe) << endl;
    return 0;
}