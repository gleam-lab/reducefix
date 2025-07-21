#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> a(M), b(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> pieces;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
        pieces.insert({a[i], b[i]});
    }
    i64 unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    for (auto d : diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        unsafe += x_max - x_min + 1;
    }
    for (auto d : diag2) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        unsafe += x_max - x_min + 1;
    }
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diag1.count(r + c) || diag2.count(r - c)) {
                unsafe--;
            }
        }
    }
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (x >= 1 && x <= N && y >= 1 && y <= N && !pieces.count({x, y})) {
                    if (rows.count(x) || cols.count(y)) {
                        unsafe--;
                    }
                }
            }
        }
    }
    i64 total_safe = N * N - unsafe;
    cout << total_safe << "\n";
    return 0;
}