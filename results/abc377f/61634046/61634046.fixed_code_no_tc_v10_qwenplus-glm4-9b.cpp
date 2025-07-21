#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // 1D prefix sums indicating the presence of a piece in rows, columns, and diagonals
    vector<int> row_presence(n + 1, 0), col_presence(n + 1, 0);
    vector<vector<int>> diag_presence(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> anti_diag_presence(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int r = pieces[i].first;
        int c = pieces[i].second;

        row_presence[r]++;
        col_presence[c]++;
        diag_presence[r][c]++;
        anti_diag_presence[r][n - c]++;
    }

    ll total_empty_squares = 0;

    // Total squares minus the sum of squares covered by rows, columns, and both diagonals
    total_empty_squares += (ll)n * n - (ll)n * n + (ll)n * row_presence[1] - (ll)n * col_presence[1] + (ll)n * n - (ll)n * n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            total_empty_squares -= (ll)diag_presence[i][j];
            total_empty_squares -= (ll)anti_diag_presence[i][j];
        }
    }

    cout << total_empty_squares << endl;

    return 0;
}