#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        pieces[i] = {x, y};
    }

    // Initialize the number of free squares
    ll free_squares = n * n;

    // Mark squares that are captured by existing pieces
    vector<vector<bool>> captured(n + 1, vector<bool>(n + 1, false));
    for (auto &p : pieces) {
        captured[p.first][p.second] = true;
        captured[p.second][p.first] = true; // Diagonal 1 (x + y = constant)
        captured[p.first - p.second + n][p.second] = true; // Diagonal 2 (x - y = constant)
        captured[p.first + p.second - n][p.second] = true; // Diagonal 3 (x + y = n + constant)
    }

    // Calculate the number of free squares
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (!captured[i][j]) {
                free_squares--;
            }
        }
    }

    // Output the number of free squares
    cout << free_squares << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int NT = 1;
    while (NT--) solve();
    return 0;
}