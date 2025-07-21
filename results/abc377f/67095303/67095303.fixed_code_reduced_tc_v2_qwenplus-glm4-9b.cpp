#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<pair<int, int>> pieces;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.emplace_back(x, y);
    }

    // Calculate the number of rows and columns that are completely blocked
    int blocked_rows = 0, blocked_cols = 0;
    for (const auto& p : pieces) {
        if (p.first == 1) blocked_rows++; // Entire first row is blocked
        if (p.first == n) blocked_rows++; // Entire last row is blocked
        if (p.second == 1) blocked_cols++; // Entire first column is blocked
        if (p.second == n) blocked_cols++; // Entire last column is blocked
    }

    // Calculate the number of blocked diagonals
    int blocked_diag1 = 0, blocked_diag2 = 0;
    for (const auto& p : pieces) {
        // Diagonal i + j = constant
        if (p.first + p.second == n + 1) blocked_diag1++;
        if (p.first + p.second == 2) blocked_diag1++;
        // Diagonal i - j = constant
        if (p.first - p.second == n + 1) blocked_diag2++;
        if (p.first - p.second == 1) blocked_diag2++;
    }

    // Total number of empty cells
    int total_cells = n * n;
    // Subtract blocked cells
    int blocked_cells = blocked_rows + blocked_cols + blocked_diag1 + blocked_diag2;

    // Output the number of cells where you can place the piece
    cout << total_cells - blocked_cells << endl;

    return 0;
}