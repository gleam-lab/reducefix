#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<vector<int>> row captured(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> col captured(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> d1 captured(2 * N + 1, vector<int>(2 * N + 1, 0));
    vector<vector<int>> d2 captured(2 * N + 1, vector<int>(2 * N + 1, 0));

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        row[a][b] = 1;
        col[b][a] = 1;
        d1[a + b][a - b + N] = 1;
        d2[a + b][a - b + N] = 1;
    }

    long long totalSquares = N * N;
    long long capturedSquares = 0;

    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            if (row[i][j] || col[j][i] || d1[i + j][i - j + N] || d2[i + j][i - j + N]) {
                capturedSquares++;
            }
        }
    }

    cout << totalSquares - capturedSquares << endl;

    return 0;
}