#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9;
const int MAX_M = 1e3;

long long n, m;
vector<pair<long long, long long>> pieces;

bool valid(long long x, long long y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<long long> rows, cols, diags1, diags2;
    for (const auto& [x, y] : pieces) {
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x - y);
        diags2.insert(x + y);
    }

    long long total_squares = n * n;
    long long covered_by_rows = rows.size() * n;
    long long covered_by_cols = cols.size() * n;
    long long covered_by_diags1 = diags1.size() * n;
    long long covered_by_diags2 = diags2.size() * n;

    long long covered_twice_by_rows_and_cols = rows.size() * cols.size();
    long long covered_twice_by_rows_and_diags1 = rows.size() * diags1.size();
    long long covered_twice_by_rows_and_diags2 = rows.size() * diags2.size();
    long long covered_twice_by_cols_and_diags1 = cols.size() * diags1.size();
    long long covered_twice_by_cols_and_diags2 = cols.size() * diags2.size();

    long long covered_three_times_by_all = 0;

    cout << total_squares - (covered_by_rows + covered_by_cols + covered_by_diags1 + covered_by_diags2 -
                           covered_twice_by_rows_and_cols - covered_twice_by_rows_and_diags1 -
                           covered_twice_by_rows_and_diags2 - covered_twice_by_cols_and_diags1 -
                           covered_twice_by_cols_and_diags2 +
                           covered_three_times_by_all);

    return 0;
}