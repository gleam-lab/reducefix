#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    // Count how many cells are covered by any of the lines
    unordered_set<string> covered;

    auto add_row = [&](ll r) {
        for (ll c = 1; c <= N; ++c) {
            covered.emplace(to_string(r) + "," + to_string(c));
        }
    };

    auto add_col = [&](ll c) {
        for (ll r = 1; r <= N; ++r) {
            covered.emplace(to_string(r) + "," + to_string(c));
        }
    };

    auto add_diag1 = [&](ll d) {
        // x - y = d => y = x - d
        ll start_y = max(1LL, 1LL - d);
        ll end_y = min(N, N - d);
        for (ll y = start_y; y <= end_y; ++y) {
            ll x = y + d;
            covered.emplace(to_string(x) + "," + to_string(y));
        }
    };

    auto add_diag2 = [&](ll s) {
        // x + y = s => y = s - x
        ll start_x = max(1LL, s - N);
        ll end_x = min(N, s - 1);
        for (ll x = start_x; x <= end_x; ++x) {
            ll y = s - x;
            covered.emplace(to_string(x) + "," + to_string(y));
        }
    };

    for (ll r : rows) add_row(r);
    for (ll c : cols) add_col(c);
    for (ll d : diag1) add_diag1(d);
    for (ll s : diag2) add_diag2(s);

    ll total_covered = covered.size();
    ll total_squares = N * N;
    ll result = total_squares - total_covered;

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}