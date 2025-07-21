#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define N 1005

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    unordered_set<int> captured_rows, captured_cols, captured_main_diag, captured_anti_diag;

    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        pieces[i].first--; // Convert to 0-indexed
        pieces[i].second--;

        // Mark the row, column, and both diagonals as captured
        captured_rows.insert(pieces[i].first);
        captured_cols.insert(pieces[i].second);
        captured_main_diag.insert(pieces[i].first - pieces[i].second);
        captured_anti_diag.insert(pieces[i].first + pieces[i].second);
    }

    // Calculate the number of captured squares
    int captured = captured_rows.size() * n
                  + captured_cols.size() * n
                  + captured_main_diag.size() * n
                  + captured_anti_diag.size() * n
                  - captured_rows.size() * captured_cols.size() // Overcounted rows and cols
                  - captured_rows.size() * captured_main_diag.size() // Overcounted rows and main diag
                  - captured_cols.size() * captured_anti_diag.size() // Overcounted cols and anti diag
                  + captured_main_diag.size() * captured_anti_diag.size(); // Overcounted main diag and anti diag

    // Total squares minus captured squares gives the number of safe squares
    cout << n * n - captured << endl;

    return 0;
}