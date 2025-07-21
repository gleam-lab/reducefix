#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces;
    vector<vector<bool>> captured(N + 4, vector<bool>(N + 4, false));

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);

        // Capture the reachable cells of the current piece
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (dx == 0 && dy == 0) continue;

                int nx = a + dx;
                int ny = b + dy;

                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    captured[nx][ny] = true;
                }
            }
        }
    }

    long long count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!captured[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}