#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces.emplace_back(x, y);
    }

    // Count capture squares for each line and diagonals
    vector<ll> rowcapture(n, 0);
    vector<ll> colcapture(n, 0);
    vector<ll> diagcapture(2 * n, 0);
    vector<ll> antidiagcapture(2 * n, 0);

    for (const auto& p : pieces) {
        rowcapture[p.first - 1] += 1;
        colcapture[p.second - 1] += 1;
        diagcapture[p.first - 1 + p.second - 1] += 1;
        antidiagcapture[p.first - 1 - p.second + n - 1] += 1;
    }

    // Calculate the number of capture-free squares
    ll free_squares = n * n;
    for (ll i = 0; i < n; ++i) {
        free_squares -= rowcapture[i];
        free_squares -= colcapture[i];
        free_squares -= diagcapture[i];
        free_squares -= antidiagcapture[i];
    }

    // For each line, we need to account for overlapping captures
    for (ll i = 0; i < n; ++i) {
        if (rowcapture[i] > 0 || colcapture[i] > 0) {
            free_squares--;
        }
    }

    // Subtract the overlapping captures on diagonals
    for (ll i = 0; i < 2 * n; ++i) {
        if (diagcapture[i] > 0 || antidiagcapture[i] > 0) {
            free_squares--;
        }
    }

    cout << free_squares << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    ll NT = 1;
    // cin >> NT;
    while (NT--) solve();
    return 0;
}