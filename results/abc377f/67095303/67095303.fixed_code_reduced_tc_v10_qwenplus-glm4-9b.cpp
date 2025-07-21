#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Unordered sets to keep track of occupied rows, columns, and diagonals
    unordered_set<int> occupied_rows, occupied_cols, occupied_diag1, occupied_diag2;

    // Populate the sets with occupied rows, columns, and diagonals
    for (const auto &p : pieces) {
        occupied_rows.insert(p.first);
        occupied_cols.insert(p.second);
        occupied_diag1.insert(p.first + p.second);
        occupied_diag2.insert(p.first - p.second);
    }

    // Calculate the number of free squares
    long long free_squares = n * n;

    // Subtract the occupied rows and columns
    free_squares -= occupied_rows.size();
    free_squares -= occupied_cols.size();

    // Subtract the occupied diagonals
    for (const auto &d : occupied_diag1) {
        long long min_n = max(1LL, -d);
        long long max_n = min(n, d);
        free_squares -= max_n - min_n + 1;
    }

    for (const auto &d : occupied_diag2) {
        long long min_n = max(1LL, -d);
        long long max_n = min(n, d);
        free_squares -= max_n - min_n + 1;
    }

    cout << free_squares << endl;

    return 0;
}