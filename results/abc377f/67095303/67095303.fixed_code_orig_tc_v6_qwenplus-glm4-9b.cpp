#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    set<int> rows, cols, diag_sum, diag_diff;
    vector<pair<int, int>> pieces(m);

    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        rows.insert(pieces[i].first);
        cols.insert(pieces[i].second);
        diag_sum.insert(pieces[i].first + pieces[i].second);
        diag_diff.insert(pieces[i].first - pieces[i].second);
    }

    long long total_cells = n * n;
    long long captured_by_rows = rows.size();
    long long captured_by_cols = cols.size();
    long long captured_by_diag_sum = diag_sum.size();
    long long captured_by_diag_diff = diag_diff.size();

    // Calculate intersections
    set<int> diag_sum_row, diag_sum_col, diag_diff_row, diag_diff_col;
    for (int d : diag_sum) {
        for (int i = 1; i <= n; ++i) {
            if (i + d <= n) diag_sum_row.insert(i);
            if (i - d >= 1) diag_sum_col.insert(i);
        }
    }
    for (int d : diag_diff) {
        for (int i = 1; i <= n; ++i) {
            if (i + d <= n) diag_diff_row.insert(i);
            if (i - d >= 1) diag_diff_col.insert(i);
        }
    }

    captured_by_diag_sum -= diag_sum_row.size();
    captured_by_diag_sum -= diag_sum_col.size();
    captured_by_diag_diff -= diag_diff_row.size();
    captured_by_diag_diff -= diag_diff_col.size();

    long long ans = total_cells - captured_by_rows - captured_by_cols - captured_by_diag_sum - captured_by_diag_diff;
    cout << ans << endl;

    return 0;
}