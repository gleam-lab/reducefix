#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.emplace(a, b);
    }

    ll total = N * N;

    // Subtract all squares attackable via row, column, diagonal
    total -= rows.size() * N;
    total -= cols.size() * N;
    for (auto d : diag1) {
        ll count = (N - abs(d));
        total -= count;
    }
    for (auto d : diag2) {
        ll count = (N - abs(N - d));
        total -= count;
    }

    // Add back intersections of row-col
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0) {
                total += 1;
            }
        }
    }

    // Add back intersections of row-diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c < 1 || c > N) continue;
            if (occupied.count({r, c}) == 0) {
                total += 1;
            }
        }
    }

    // Add back intersections of row-diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c < 1 || c > N) continue;
            if (occupied.count({r, c}) == 0) {
                total += 1;
            }
        }
    }

    // Add back intersections of col-diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r < 1 || r > N) continue;
            if (occupied.count({r, c}) == 0) {
                total += 1;
            }
        }
    }

    // Add back intersections of col-diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r < 1 || r > N) continue;
            if (occupied.count({r, c}) == 0) {
                total += 1;
            }
        }
    }

    // Add back intersections of diag1-diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > N || c < 1 || c > N) continue;
            if (occupied.count({r, c}) == 0) {
                total += 1;
            }
        }
    }

    cout << max(0LL, total) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}