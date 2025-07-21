#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j
    set<pll> pieces;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    // Total safe cells = total empty cells not on any attacked line
    ll total_safe = (N - rows.size()) * (N - cols.size());

    // We will count how many attacked positions are in the intersections of diagonals with rows/cols
    set<pll> attacked;

    // Process diag1: i - j = c
    for (ll c : diag1) {
        // This diagonal intersects row i at (i, i - c)
        for (ll i : rows) {
            ll j = i - c;
            if (1 <= j && j <= N && !pieces.count({i, j})) {
                attacked.insert({i, j});
            }
        }

        // This diagonal intersects column j at (j + c, j)
        for (ll j : cols) {
            ll i = j + c;
            if (1 <= i && i <= N && !pieces.count({i, j})) {
                attacked.insert({i, j});
            }
        }
    }

    // Process diag2: i + j = c
    for (ll c : diag2) {
        // This diagonal intersects row i at (i, c - i)
        for (ll i : rows) {
            ll j = c - i;
            if (1 <= j && j <= N && !pieces.count({i, j})) {
                attacked.insert({i, j});
            }
        }

        // This diagonal intersects column j at (c - j, j)
        for (ll j : cols) {
            ll i = c - j;
            if (1 <= i && i <= N && !pieces.count({i, j})) {
                attacked.insert({i, j});
            }
        }
    }

    // Subtract the number of attacked positions
    cout << (total_safe - (ll)attacked.size()) << endl;
    return 0;
}