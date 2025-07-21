#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void solve(int H, int W, int Y, const vector<vector<int>>& A) {
    // Initialize the island grid with the same height
    vector<vector<int>> island(H, vector<int>(W, 0));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the sink heights
    vector<vector<int>> sink(H, vector<int>(W, 0));

    // Initialize the queue with the edge cells that are directly at sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                island[i][j] = A[i][j];
                sink[i][j] = 1;
                pq.push({A[i][j], {i, j}});
            }
        }
    }

    // Process the cells according to the sinking rules
    while (!pq.empty()) {
        auto [h, p] = pq.top();
        auto [r, c] = p;
        pq.pop();

        for (int k = 0; k < 4; ++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                if (island[nr][nc] > h) {
                    island[nr][nc] = h; // Sink to the same level as the neighbor
                    sink[nr][nc] = min(sink[r][c] + 1, Y); // Increase the sinking year if necessary
                    pq.push({island[nr][nc], {nr, nc}});
                }
            }
        }
    }

    // Calculate the area above the sea level for each year
    for (int year = 1; year <= Y; ++year) {
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (sink[i][j] > year) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << '\n';
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    solve(H, W, Y, A);
    return 0;
}