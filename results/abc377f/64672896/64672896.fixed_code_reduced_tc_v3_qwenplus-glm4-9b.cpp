#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = long long;

int main() {
    i64 N, M;
    cin >> N >> M;

    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    vector<i64> rows(N + 1), cols(N + 1), diag1(N + 1), diag2(N + 1), tridiag1(N + 1), tridiag2(N + 1);
    for (const auto& p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        diag1[p.first + p.second]++;
        diag2[p.first - p.second]++;
        tridiag1[p.first + p.second - 1]++;
        tridiag2[p.first - p.second + 1]++;
    }

    i64 ans = N * N;
    for (i64 i = 1; i <= N; ++i) {
        ans -= rows[i] - 1;        // Subtract rows that are fully covered
        ans -= cols[i] - 1;        // Subtract columns that are fully covered
        ans -= diag1[i] - 1;       // Subtract main diagonals that are fully covered
        ans -= diag2[i] - 1;       // Subtract secondary diagonals that are fully covered
        ans -= tridiag1[i] - 1;    // Subtract triangles going down and left
        ans -= tridiag2[i] - 1;    // Subtract triangles going up and left
    }

    cout << ans << '\n';
    return 0;
}