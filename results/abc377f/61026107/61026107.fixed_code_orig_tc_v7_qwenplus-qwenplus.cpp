#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Struct to represent a point (for debugging or map use if needed)
struct Point {
    ll x, y;
};

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
        occupied.insert({x, y});
    }

    // Total number of threatened cells
    ll threatened = 0;

    // Rows and Columns
    threatened += rows.size() * N;
    threatened += cols.size() * N;

    // Diagonals
    for (auto d : diag1) {
        ll count = N - abs(d);
        if (count > 0) threatened += count;
    }

    // Anti-diagonals
    for (auto d : diag2) {
        ll count = N - abs(N - d);
        if (count > 0) threatened += count;
    }

    // Inclusion-Exclusion: remove overcounts

    // Row-Column overlaps
    for (auto r : rows) {
        for (auto c : cols) {
            if (!occupied.count({r, c})) threatened--;
        }
    }

    // Row-Diag1 overlaps
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) threatened--;
        }
    }

    // Row-Diag2 overlaps
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N) threatened--;
        }
    }

    // Col-Diag1 overlaps
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N) threatened--;
        }
    }

    // Col-Diag2 overlaps
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N) threatened--;
        }
    }

    // Diag1-Diag2 overlaps
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = d2 - r;
            if (1 <= r && r <= N && 1 <= c && c <= N) threatened--;
        }
    }

    // Add back double-subtracted cases due to triple overlap
    for (auto r : rows) {
        for (auto c : cols) {
            for (auto d1 : diag1) {
                if (r - c == d1) threatened++;
            }
        }
    }

    // Total available positions minus threatened ones
    ll total = N * N - threatened;
    cout << total << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}