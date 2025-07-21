#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<set<int>> rows, cols, diag1, diag2;

int main() {
    int N, M;
    cin >> N >> M;

    int a, b, d;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        rows.push_back({a});
        cols.push_back({b});
        diag1.push_back({a + b});
        diag2.push_back({a - b});
    }

    for (auto& row : rows) sort(row.begin(), row.end());
    for (auto& col : cols) sort(col.begin(), col.end());
    for (auto& diag : diag1) sort(diag.begin(), diag.end());
    for (auto& diag : diag2) sort(diag.begin(), diag.end());

    int ans = N * N;

    // Eliminate captured squares by rows
    set<int> covered_rows;
    for (int i = 1; i <= N; i++) {
        if (rows[i].size() > 1) covered_rows.insert(i);
    }
    ans -= covered_rows.size() * N;

    // Eliminate captured squares by columns
    set<int> covered_cols;
    for (int i = 1; i <= N; i++) {
        if (cols[i].size() > 1) covered_cols.insert(i);
    }
    ans -= covered_cols.size() * N;

    // Eliminate captured squares by diagonals
    set<int> covered_diag1, covered_diag2;
    for (int i = 2; i <= 2 * N; i++) {
        if (diag1[i].size() > 1) covered_diag1.insert(i);
    }
    for (int i = -N + 2; i <= N - 2; i++) {
        if (diag2[i].size() > 1) covered_diag2.insert(i);
    }
    ans -= (covered_diag1.size() + covered_diag2.size()) * N;

    // Apply inclusion-exclusion principle
    for (int r : covered_rows) {
        for (int c : covered_cols) {
            if (r + c > 2 * N) {
                ans -= 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}