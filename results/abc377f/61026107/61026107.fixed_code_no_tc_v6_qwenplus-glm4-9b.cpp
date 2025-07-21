#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // The set of captured rows, columns, diagonals
    set<ll> capturedRows, capturedCols, capturedDiag1, capturedDiag2;
    for (auto& p : pieces) {
        capturedRows.insert(p.first);
        capturedCols.insert(p.second);
        capturedDiag1.insert(p.first + p.second);
        capturedDiag2.insert(p.first - p.second);
    }

    // Calculate the number of empty squares that are not captured by any pieces
    ll totalEmptySquares = n * n;
    ll capturedRowsCount = capturedRows.size();
    ll capturedColsCount = capturedCols.size();
    ll capturedDiag1Count = capturedDiag1.size();
    ll capturedDiag2Count = capturedDiag2.size();

    // Subtract captured rows, columns, and intersections
    totalEmptySquares -= capturedRowsCount; // Subtracted rows
    totalEmptySquares -= capturedColsCount; // Subtracted columns
    totalEmptySquares -= capturedDiag1Count; // Subtracted main diagonals
    totalEmptySquares -= capturedDiag2Count; // Subtracted anti-diagonals

    // Subtract twice because each row, column, diagonal was subtracted once, and they intersect at most once
    totalEmptySquares -= capturedRowsCount;
    totalEmptySquares -= capturedColsCount;
    totalEmptySquares -= capturedDiag1Count;
    totalEmptySquares -= capturedDiag2Count;

    // Each intersection of captured rows and columns can be calculated separately
    // We need to subtract these intersections exactly once
    set<pair<ll, ll>> intersections;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (capturedRows.count(i) && capturedCols.count(j)) {
                intersections.insert({i, j});
            }
        }
    }
    totalEmptySquares -= intersections.size();

    cout << totalEmptySquares << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) solve();
    return 0;
}