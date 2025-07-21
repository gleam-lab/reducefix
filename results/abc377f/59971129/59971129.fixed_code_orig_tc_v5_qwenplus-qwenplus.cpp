#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<pll> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total safe positions initially = all empty squares not in attacked lines
    ll total_safe = (N - rows.size()) * (N - cols.size());

    // Collect all attacked cells on diagonals
    set<pll> attacked;

    for (ll d : diag1) {
        // For i - j = d => i = j + d
        for (ll j = 1; j <= N; ++j) {
            ll i = j + d;
            if (1 <= i && i <= N && !occupied.count({i, j})) {
                attacked.insert({i, j});
            }
        }
        for (ll i = 1; i <= N; ++i) {
            ll j = i - d;
            if (1 <= j && j <= N && !occupied.count({i, j})) {
                attacked.insert({i, j});
            }
        }
    }

    for (ll d : diag2) {
        // For i + j = d => j = d - i
        for (ll i = 1; i <= N; ++i) {
            ll j = d - i;
            if (1 <= j && j <= N && !occupied.count({i, j})) {
                attacked.insert({i, j});
            }
        }
        for (ll j = 1; j <= N; ++j) {
            ll i = d - j;
            if (1 <= i && i <= N && !occupied.count({i, j})) {
                attacked.insert({i, j});
            }
        }
    }

    // Subtract attacked diagonal cells that are otherwise counted as safe
    ll overlap = 0;
    for (auto p : attacked) {
        if (!rows.count(p.first) && !cols.count(p.second)) {
            ++overlap;
        }
    }

    cout << (total_safe - overlap) << endl;
    return 0;
}