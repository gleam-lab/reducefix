#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAX_N = 1e9;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// Function to calculate the number of valid squares
ll countValidSquares(ll n, const vector<pll>& pieces) {
    set<ll> rows, cols, diag1, diag2;
    unordered_set<ll> captured_squares;

    for (const auto& piece : pieces) {
        rows.insert(piece.first);
        cols.insert(piece.second);
        diag1.insert(piece.first - piece.second);
        diag2.insert(piece.first + piece.second);

        // Add squares in the same row, column, and diagonals as captured squares
        for (ll i = 1; i <= n; ++i) {
            captured_squares.insert({piece.first, i});
            captured_squares.insert({i, piece.second});
            captured_squares.insert({piece.first - piece.second + i, i});
            captured_squares.insert({piece.first + piece.second - i, i});
        }
    }

    // Remove duplicate captures
    captured_squares.erase(rows.begin(), rows.end());
    captured_squares.erase(cols.begin(), cols.end());
    captured_squares.erase(diag1.begin(), diag1.end());
    captured_squares.erase(diag2.begin(), diag2.end());

    return n * n - captured_squares.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<pll> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << countValidSquares(n, pieces) << endl;

    return 0;
}