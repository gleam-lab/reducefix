#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 safe_squares = N * N - M;

    for (const auto& [a, b] : pieces) {
        if (rows.count(a)) --safe_squares;
        if (cols.count(b)) --safe_squares;
        if (diag1.count(a + b)) --safe_squares;
        if (diag2.count(a - b)) --safe_squares;
    }

    cout << safe_squares << '\n';

    return 0;
}