#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    
    vector<array<i64, 2>> pieces(M);
    set<pair<i64, i64>> captured_squares;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};

        // Capture horizontally
        for (i64 j = 1; j <= N; ++j) {
            if (j != b) {
                captured_squares.insert({a, j});
            }
        }

        // Capture vertically
        for (i64 i2 = 1; i2 <= N; ++i2) {
            if (i2 != a) {
                captured_squares.insert({i2, b});
            }
        }

        // Capture diagonally (positive slope)
        for (i64 d = 1; d <= N; ++d) {
            if (a + d <= N && b + d <= N) {
                captured_squares.insert({a + d, b + d});
            }
            if (a - d > 0 && b - d > 0) {
                captured_squares.insert({a - d, b - d});
            }
        }

        // Capture diagonally (negative slope)
        for (i64 d = 1; d <= N; ++d) {
            if (a + d <= N && b - d > 0) {
                captured_squares.insert({a + d, b - d});
            }
            if (a - d > 0 && b + d <= N) {
                captured_squares.insert({a - d, b + d});
            }
        }
    }

    // Total empty squares minus captured squares
    cout << N * N - captured_squares.size() << endl;

    return 0;
}