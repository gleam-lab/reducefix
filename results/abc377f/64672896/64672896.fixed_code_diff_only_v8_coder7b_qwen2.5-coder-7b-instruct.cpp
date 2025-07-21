#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    
    set<pair<i64, i64>> pieces;
    unordered_set<i64> sum_lines, diff_lines, row_lines, col_lines;

    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        sum_lines.insert(a + b);
        diff_lines.insert(a - b);
        row_lines.insert(a);
        col_lines.insert(b);
    }

    i64 count = 0;

    for (i64 i = 1; i <= N; ++i) {
        for (i64 j = 1; j <= N; ++j) {
            if (pieces.count({i, j})) continue;
            bool valid = true;

            for (auto line : sum_lines) {
                if (line == i + j) {
                    valid = false;
                    break;
                }
            }

            for (auto line : diff_lines) {
                if (line == i - j) {
                    valid = false;
                    break;
                }
            }

            if (row_lines.count(i)) valid = false;
            if (col_lines.count(j)) valid = false;

            if (valid) ++count;
        }
    }

    cout << count << '\n';

    return 0;
}