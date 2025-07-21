#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool inBounds(int i, int j, int n) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<int> rows, cols, diags1, diags2;

    for (const auto& [i, j] : pieces) {
        rows.insert(i);
        cols.insert(j);
        diags1.insert(i - j);
        diags2.insert(i + j);
    }

    int total_squares = n * n;
    int captured_by_rows = rows.size() * n;
    int captured_by_cols = cols.size() * n;
    int captured_by_diags1 = diags1.size() * n;
    int captured_by_diags2 = diags2.size() * n;

    int twice_captured = 0;

    for (const auto& [i, j] : pieces) {
        int diag1 = i - j;
        int diag2 = i + j;

        twice_captured += (rows.count(i) > 1) + (cols.count(j) > 1) +
                          (diags1.count(diag1) > 1) + (diags2.count(diag2) > 1);
    }

    int result = total_squares - (captured_by_rows + captured_by_cols + captured_by_diags1 + captured_by_diags2 - twice_captured);
    cout << result << endl;

    return 0;
}