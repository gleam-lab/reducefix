#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        i64 r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index
        pieces[i] = {r, c};
    }

    // Use sets to track unique capturable lines
    set<i64> rows, cols, diag1, diag2, anti_diag1, anti_diag2;
    for (auto p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
        anti_diag1.insert(p.first + N - p.second - 1);
        anti_diag2.insert(p.first - N + p.second + 1);
    }

    // Count capturable squares
    i64 capturable = N * N;
    for (auto r : rows) capturable -= rows.count(r);
    for (auto c : cols) capturable -= cols.count(c);
    for (auto d : diag1) capturable -= diag1.count(d);
    for (auto d : diag2) capturable -= diag2.count(d);
    for (auto d : anti_diag1) capturable -= anti_diag1.count(d);
    for (auto d : anti_diag2) capturable -= anti_diag2.count(d);

    cout << capturable << '\n';

    return 0;
}