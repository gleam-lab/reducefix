#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int MAX_H = 1000;
const int MAX_W = 1000;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> flooded(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the queue with the boundary cells and cells that are already below the water level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || A[i][j] <= Y - 1) {
                q.push({i, j});
                flooded[i][j] = true;
            }
        }
    }

    vector<ll> remaining_area(Y + 1, 0);

    while (!q.empty()) {
        int year = Y - 1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            // Check adjacent cells
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && !flooded[ni][nj] && A[ni][nj] <= year) {
                        flooded[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
        remaining_area[year] = H * W - q.size(); // Calculate remaining area
    }

    for (int i = 0; i < Y; ++i) {
        cout << remaining_area[i] << endl;
    }

    return 0;
}