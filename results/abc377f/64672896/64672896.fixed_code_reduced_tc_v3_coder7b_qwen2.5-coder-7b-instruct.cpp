#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<int,2>> g(M);
    set<array<int,2>> S;
    for (int i = 0; i < M; i ++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        S.insert({a, b});
    }
    
    auto countCapturableSquares = [&](bool rowCapture, bool colCapture, bool diagCapture1, bool diagCapture2) {
        i64 count = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                bool isCaptured = false;
                if (rowCapture && S.count({i, j})) isCaptured = true;
                if (colCapture && S.count({j, i})) isCaptured = true;
                if (diagCapture1 && S.count({i + j, i - j})) isCaptured = true;
                if (diagCapture2 && S.count({i - j, i + j})) isCaptured = true;
                if (!isCaptured) count++;
            }
        }
        return count;
    };

    i64 totalEmptySquares = N * N - M;
    i64 ans = totalEmptySquares - 
              countCapturableSquares(true, false, false, false) - 
              countCapturableSquares(false, true, false, false) - 
              countCapturableSquares(false, false, true, false) - 
              countCapturableSquares(false, false, false, true) +
              countCapturableSquares(true, true, false, false) +
              countCapturableSquares(true, false, true, false) +
              countCapturableSquares(true, false, false, true) +
              countCapturableSquares(false, true, true, false) +
              countCapturableSquares(false, true, false, true) +
              countCapturableSquares(false, false, true, true);

    cout << ans << "\n";

    return 0;
}