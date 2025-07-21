#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define the directions for the flood fill algorithm.
const int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void sink(int H, int W, const vector<vector<int>>& A, vector<vector<bool>>& F, int sea_level) {
    queue<pair<int, int>> Q;

    // Add all cells on the edge of the island or at sea level to the queue.
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || A[i][j] == sea_level) {
                Q.push({i, j});
            }
        }
    }

    // Perform the flood fill algorithm.
    while (!Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();

        for (int k = 0; k < 8; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj] && A[ni][nj] > sea_level) {
                F[ni][nj] = false;
                Q.push({ni, nj});
            }
        }
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> F(H, vector<bool>(W, true));
    long long ans = H * W;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int y = 0; y < Y; ++y) {
        sink(H, W, A, F, y);
        long long remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (F[i][j]) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}