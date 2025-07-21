#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Count the number of occupied squares in each line, column, and diagonal
    vector<ll> rows(n + 1), cols(n + 1), main_diagonals(n + 1), anti_diagonals(n + 1);
    for (auto& p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        main_diagonals[p.first + p.second]++;
        anti_diagonals[p.first - p.second + n]++;
    }

    // Calculate the number of squares that can be placed
    ll free_squares = n * n;
    for (ll i = 1; i <= n; ++i) {
        free_squares -= rows[i];
        free_squares -= cols[i];
        free_squares -= main_diagonals[i];
        free_squares -= anti_diagonals[i];
    }

    cout << free_squares << endl;
    return 0;
}