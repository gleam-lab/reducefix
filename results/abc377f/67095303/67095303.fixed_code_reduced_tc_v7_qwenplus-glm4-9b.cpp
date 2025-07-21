#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces;
    for (long long i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);
    }

    // Store unique rows, columns, and diagonals
    unordered_set<int> rows, cols, diag1, diag2;

    // i+j
    for (const auto& p : pieces) {
        diag1.insert(p.first + p.second);
    }

    // i-j
    for (const auto& p : pieces) {
        diag2.insert(p.first - p.second);
    }

    // Rows and columns
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
    }

    // Calculate the number of empty cells not captured by any piece
    long long empty = n * n; // Total cells

    // Subtract rows and columns covered by pieces
    empty -= rows.size();
    empty -= cols.size();

    // Subtract cells on main diagonals
    empty -= diag1.size();
    empty -= diag2.size();

    // Subtract intersection of main and anti-diagonals
    empty -= diag1.size() * 2;

    cout << empty << endl;

    return 0;
}