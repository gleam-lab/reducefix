#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> pieces_x(m), pieces_y(m);
    
    for (ll i = 0; i < m; ++i) {
        cin >> pieces_x[i] >> pieces_y[i];
    }

    set<ll> row, col, diag1, diag2;

    // Collecting rows, columns, and diagonals that are occupied by pieces
    for (ll i = 0; i < m; ++i) {
        row.insert(pieces_x[i]);
        col.insert(pieces_y[i]);
        diag1.insert(pieces_x[i] + pieces_y[i]);
        diag2.insert(pieces_x[i] - pieces_y[i]);
    }

    // Calculate the number of free cells in rows, columns, diagonals
    ll free_rows = n - row.size(), free_cols = n - col.size();
    ll free_diag1 = n - diag1.size(), free_diag2 = n - diag2.size();

    // Calculate the number of free cells in 2x2 blocks
    ll free_2x2_blocks = (n - 1) * (n - 1) - (free_diag1 + free_diag2 + free_rows + free_cols - 3 * n);

    // Output the number of free cells
    cout << free_2x2_blocks << endl;

    return 0;
}