#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long n, m;
    cin >> n >> m;

    set<long long> rows, cols, ups, downs;
    unordered_set<long long> captured_rows, captured_cols, captured_ups, captured_downs;

    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        ups.insert(y - x);
        downs.insert(x + y);
    }

    for (auto& row : rows) {
        if (!captured_rows.count(row)) {
            for (auto& col : cols) {
                if (!captured_cols.count(col)) {
                    auto up_key = col - row;
                    auto down_key = row + col;
                    if (!captured_ups.count(up_key) && !captured_downs.count(down_key)) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}