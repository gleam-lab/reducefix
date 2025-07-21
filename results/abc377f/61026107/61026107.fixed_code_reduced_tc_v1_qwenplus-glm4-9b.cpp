#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Counters for captured rows, columns, diagonals
    ll capturedRows = 0, capturedCols = 0, capturedDiag1 = 0, capturedDiag2 = 0;

    // Check which rows, columns, and diagonals are captured
    for (auto& p : pieces) {
        capturedRows |= (1LL << (p.first - 1));
        capturedCols |= (1LL << (p.second - 1));
        capturedDiag1 |= (1LL << (p.first - p.second));
        capturedDiag2 |= (1LL << (p.first + p.second - 2));
    }

    // Calculate the number of empty squares
    ll totalSquares = n * n;
    ll usedSquares = 0;

    // Calculate used square in rows and columns
    for (ll i = 0; i < n; i++) {
        if (capturedRows & (1LL << i)) usedSquares++;
        if (capturedCols & (1LL << i)) usedSquares++;
    }

    // Calculate used square in diagonals
    for (ll i = 0; i < 2 * n - 1; i++) {
        ll row = (i + 1) / 2;
        ll col = (i + 1) % 2 == 0 ? i / 2 + 1 : n - (i / 2) - 1;
        if (capturedDiag1 & (1LL << (row - 1))) usedSquares++;
        if (capturedDiag2 & (1LL << (row - 1))) usedSquares++;
    }

    cout << totalSquares - usedSquares << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int NT = 1;
    cin >> NT;
    while (NT--) solve();
    return 0;
}