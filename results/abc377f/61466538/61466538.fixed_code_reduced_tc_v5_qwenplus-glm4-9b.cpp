#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pll> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Helper function to count number of elements in a set
    auto count_unique = [&](const set<ll>& s) {
        return s.size();
    };

    // Count number of pieces in each row, column, and diagonals
    set<ll> rows, cols, diag1, diag2;
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first - p.second);
        diag2.insert(p.first + p.second);
    }

    // Calculate number of blocks that cannot be placed due to attacks
    ll total_blocks = n * n;
    ll blocks_in_rows = count_unique(rows) * n;
    ll blocks_in_cols = count_unique(cols) * n;
    ll blocks_in_diag1 = count_unique(diag1) * n;
    ll blocks_in_diag2 = count_unique(diag2) * n;

    // Calculate overlap for rows and columns
    set<ll> row_col_overlap, diag_col_overlap, diag_row_overlap;
    for (ll row : rows) {
        for (ll col : cols) {
            row_col_overlap.insert(row + col);
            row_col_overlap.insert(row - col);
        }
    }
    for (ll diag : diag1) {
        for (ll col : cols) {
            diag_col_overlap.insert(diag + col);
            diag_col_overlap.insert(diag - col);
        }
    }
    for (ll diag : diag2) {
        for (ll row : rows) {
            diag_row_overlap.insert(diag + row);
            diag_row_overlap.insert(diag - row);
        }
    }

    // Calculate excess blocks due to overlaps
    ll excess_row_col = count_unique(row_col_overlap);
    ll excess_diag_col = count_unique(diag_col_overlap);
    ll excess_diag_row = count_unique(diag_row_overlap);

    ll result = total_blocks;
    result -= blocks_in_rows;
    result -= blocks_in_cols;
    result -= blocks_in_diag1;
    result -= blocks_in_diag2;
    result += excess_row_col;
    result += excess_diag_col;
    result += excess_diag_row;

    cout << result;
    return 0;
}