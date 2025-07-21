#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
        pieces.insert({x, y});
    }

    // Total number of cells
    ll total = N * N;

    // Subtract attacked cells by rows, columns, diagonals, anti-diagonals
    ll attacked = 0;

    // Rows
    attacked += (ll)rows.size() * N;

    // Columns
    attacked += (ll)cols.size() * N;

    // Diagonals (x - y)
    for (auto d : diag1) {
        ll count = N - abs(d);
        if (count > 0) attacked += count;
    }

    // Anti-diagonals (x + y)
    for (auto d : diag2) {
        ll count = N - abs(N - d);
        if (count > 0) attacked += count;
    }

    // Add back over-subtracted overlaps: row & column
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if ((r - c) && diag1.count(r - c)) continue;
            if ((r + c) && diag2.count(r + c)) continue;
            attacked--;
        }
    }

    // row & diagonal
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c < 1 || c > N) continue;
            if (cols.count(c)) continue;
            if (diag2.count(r + c)) continue;
            attacked--;
        }
    }

    // row & anti-diagonal
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c < 1 || c > N) continue;
            if (cols.count(c)) continue;
            if (diag1.count(r - c)) continue;
            attacked--;
        }
    }

    // column & diagonal
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r < 1 || r > N) continue;
            if (rows.count(r)) continue;
            if (diag2.count(r + c)) continue;
            attacked--;
        }
    }

    // column & anti-diagonal
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r < 1 || r > N) continue;
            if (rows.count(r)) continue;
            if (diag1.count(r - c)) continue;
            attacked--;
        }
    }

    // diagonal & anti-diagonal
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > N || c < 1 || c > N) continue;
            if (rows.count(r)) continue;
            if (cols.count(c)) continue;
            attacked--;
        }
    }

    // Subtract all existing pieces (they were included in attacked but cannot be used)
    attacked -= M;

    ll answer = max(0LL, total - attacked);
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}