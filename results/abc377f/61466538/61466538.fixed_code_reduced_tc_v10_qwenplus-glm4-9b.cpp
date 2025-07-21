#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_map<ll, ll> row capturing, col capturing;
    unordered_map<ll, ll> diag1 capturing, diag2 capturing;

    for (auto& p : pieces) {
        row[p.first]++;
        col[p.second]++;
        diag1[p.first - p.second]++;
        diag2[p.first + p.second]++;
    }

    ll free squares = n * n;

    // Subtract squares captured by rows and columns
    for (auto& r : row) free squares -= r.second * n;
    for (auto& c : col) free squares -= c.second * n;

    // Add squares captured by both diagonals
    for (auto& d : diag1) free squares += d.second;
    for (auto& d : diag2) free squares += d.second;

    cout << free squares;
    return 0;
}