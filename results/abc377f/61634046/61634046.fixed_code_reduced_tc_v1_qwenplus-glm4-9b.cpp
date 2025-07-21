#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

const int MOD = 990000000;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Check for rows and columns that are fully covered
    vector<int> full_rows, full_cols;
    for (int i = 1; i <= n; ++i) {
        int row_covered = 1, col_covered = 1;
        for (int j = 0; j < m; ++j) {
            if (points[j].x == i) row_covered++;
            if (points[j].y == i) col_covered++;
        }
        if (row_covered == m) full_rows.push_back(i);
        if (col_covered == m) full_cols.push_back(i);
    }

    // Calculate the number of safe squares
    ll safe_squares = (ll)(n) * (n);

    // Subtract the number of squares covered by full rows and columns
    for (int row : full_rows) {
        safe_squares -= (ll)(n);
    }
    for (int col : full_cols) {
        safe_squares -= (ll)(n);
    }

    // Subtract the squares covered by diagonals
    vector<int> diag1, diag2, anti_diag1, anti_diag2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool found = false;
            for (int k = 0; k < m; ++k) {
                if (points[k].x + points[k].y == i + j || points[k].x - points[k].y == i - j) {
                    found = true;
                    break;
                }
            }
            if (found) {
                diag1.push_back(i + j);
                diag2.push_back((n + 1) + (n + 1) - (i + j));
                anti_diag1.push_back((n + 1) + (n + 1) - (i + j));
                anti_diag2.push_back(i - j);
            }
        }
    }

    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());
    sort(anti_diag1.begin(), anti_diag1.end());
    sort(anti_diag2.begin(), anti_diag2.end());

    int diag_covered = unique(diag1.begin(), diag1.end()) - diag1.begin();
    int diag2_covered = unique(diag2.begin(), diag2.end()) - diag2.begin();
    int anti_diag1_covered = unique(anti_diag1.begin(), anti_diag1.end()) - anti_diag1.begin();
    int anti_diag2_covered = unique(anti_diag2.begin(), anti_diag2.end()) - anti_diag2.begin();

    safe_squares -= diag_covered + diag2_covered + anti_diag1_covered + anti_diag2_covered;

    cout << (safe_squares % MOD) << endl;
    return 0;
}