#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> F(H, vector<bool>(W, false));  // F[i][j] = false means submerged
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Priority queue to process cells in decreasing order of elevation
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || A[i][j] < Y) {
                F[i][j] = true;  // This cell will be submerged at sea level Y
                pq.push({A[i][j], i * W + j});
            }
        }
    }

    int remaining_area = H * W;
    int current_year = 0;
    while (current_year < Y && !pq.empty()) {
        while (current_year <= pq.top().first && !pq.empty()) {
            int elevation = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            remaining_area--;
            int i = index / W;
            int j = index % W;

            // Check neighbors and add to queue if they will sink this year
            for (int di = -1; di <= 1; ++di) {
                int ni = i + di;
                for (int dj = -1; dj <= 1; ++dj) {
                    int nj = j + dj;
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                        if (A[ni][nj] <= elevation + 1 && !F[ni][nj]) {
                            F[ni][nj] = true;
                            pq.push({elevation + 1, ni * W + nj});
                        }
                    }
                }
            }
        }
        current_year++;
    }

    for (int year = 1; year <= Y; ++year) {
        cout << remaining_area - (H * W - H - W) << endl;  // Subtracting the area of the border
    }

    return 0;
}