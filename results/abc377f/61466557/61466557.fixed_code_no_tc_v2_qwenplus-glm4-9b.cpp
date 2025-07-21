#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll n, m;
vector< pair<int, int> > pieces;

ll count_empty_squares() {
    set<int> rows, cols, diag1, diag2;
    // Collect all occupied rows, columns, and diagonals
    for (auto &piece : pieces) {
        rows.insert(piece.first);
        cols.insert(piece.second);
        diag1.insert(piece.first - piece.second + 1);
        diag2.insert(piece.first + piece.second + 1);
    }

    // Calculate the number of empty squares
    ll total_squares = n * n;
    // Subtract squares occupied by pieces
    total_squares -= (ll)rows.size() * n;
    total_squares -= (ll)cols.size() * n;
    // Add back squares that became available because of overlapping pieces
    for (int r : rows) {
        for (int c : cols) {
            int d1 = r - c + 1;
            int d2 = r + c + 1;
            if (diag1.count(d1)) continue;
            if (diag2.count(d2)) continue;
            total_squares++;
        }
    }

    return total_squares % MOD;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    cout << count_empty_squares() << endl;
    return 0;
}