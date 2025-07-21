#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    
    set<pair<i64, i64>> pieces;
    set<i64> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 result = 0;
    for (i64 i = 1; i <= N; ++i) {
        for (i64 j = 1; j <= N; ++j) {
            if (!pieces.count({i, j}) &&
                !rows.count(i) && !cols.count(j) &&
                !diag1.count(i + j) && !diag2.count(i - j)) {
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}