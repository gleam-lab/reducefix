#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
vector<pair<int, int>> pieces;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }

    // Count the number of total squares
    int total_squares = n * n;

    // Count the number of occupied squares in rows and columns
    vector<int> rows(n + 1), cols(n + 1);
    vector<int> diag1(2 * n + 1), diag2(2 * n + 1);
    vector<int> anti_diag1(2 * n + 1), anti_diag2(2 * n + 1);

    for (auto& p : pieces) {
        int x = p.first, y = p.second;
        rows[x]++;
        cols[y]++;
        diag1[x + y]++;
        diag2[x - y]++;
        anti_diag1[x + y]++;
        anti_diag2[x - y]++;
    }

    int occupied_squares = 0;
    // Subtract occupied rows, columns, and diagonals
    for (int i = 1; i <= n; ++i) {
        occupied_squares += rows[i];
        occupied_squares += cols[i];
        occupied_squares += diag1[i];
        occupied_squares += diag2[i];
        occupied_squares += anti_diag1[i];
        occupied_squares += anti_diag2[i];
    }
    // Subtract overlaps for diagonals and anti-diagonals
    for (int i = 1; i <= 2 * n; ++i) {
        occupied_squares = max(occupied_squares, diag1[i]);
        occupied_squares = max(occupied_squares, diag2[i]);
        occupied_squares = max(occupied_squares, anti_diag1[i]);
        occupied_squares = max(occupied_squares, anti_diag2[i]);
    }

    // The answer is total squares minus occupied squares
    cout << total_squares - occupied_squares << endl;

    return 0;
}