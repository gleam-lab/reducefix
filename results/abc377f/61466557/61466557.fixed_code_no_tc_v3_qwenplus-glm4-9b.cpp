#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

// Function to calculate the number of squares that can be placed
ll countSafeSquares(ll n, vector<pair<ll, ll>>& pieces) {
    vector<ll> rows(n + 1, 0); // Tracks pieces in each row
    vector<ll> cols(n + 1, 0); // Tracks pieces in each column
    vector<ll> diag1(2 * n + 1, 0); // Tracks pieces in diagonals (i - j)
    vector<ll> diag2(2 * n + 1, 0); // Tracks pieces in diagonals (i + j)

    // Count the number of pieces in each row, column, primary diagonal, and secondary diagonal
    for (auto& piece : pieces) {
        rows[piece.first]++;
        cols[piece.second]++;
        diag1[piece.first - piece.second + n]++;
        diag2[piece.first + piece.second + n]++;
    }

    // Count the total number of safe squares
    ll safeSquares = n * n; // Total squares

    // Subtract squares that are not safe (double subtract and add once)
    safeSquares -= rows.size() * n;   // Subtract squares in each row
    safeSquares -= cols.size() * n;   // Subtract squares in each column
    safeSquares += rows.size() * cols.size(); // Add squares that are in both row and column

    // Subtract squares that are not safe due to diagonals
    for (ll d = 1; d <= 2 * n; ++d) {
        safeSquares -= diag1[d]; // Subtract squares in each primary diagonal
        safeSquares -= diag2[d]; // Subtract squares in each secondary diagonal
        if (d > n) {
            safeSquares -= diag1[d]; // Subtract the same for the secondary diagonal
        }
    }

    return safeSquares;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    cout << countSafeSquares(n, pieces);
    return 0;
}