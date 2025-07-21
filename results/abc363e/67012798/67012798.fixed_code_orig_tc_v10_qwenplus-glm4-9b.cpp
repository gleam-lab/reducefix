#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> island(H, vector<bool>(W, true));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int initial_area = 0;

    // Initialize the priority queue with sections above sea level
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || A[i][j] == 0) {
                island[i][j] = false;
            } else {
                pq.push({-A[i][j], {i, j}});
                initial_area++;
            }
        }
    }

    vector<int> years_left(initial_area, Y);

    for (int year = 1; year <= Y; year++) {
        // Use flood fill to mark all sections that will sink this year
        queue<pair<int, int>> to_process;
        while (!pq.empty()) {
            auto [neg_elevation, {x, y}] = pq.top();
            pq.pop();

            if (!island[x][y]) continue;

            to_process.push({x, y});
            island[x][y] = false;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (A[nx][ny] <= neg_elevation - year) {
                    pq.push({-A[nx][ny] - year, {nx, ny}});
                    years_left[abs(neg_elevation) - 1]--;
                }
            }
        }

        // Update remaining years for all processed sections
        while (!to_process.empty()) {
            auto [x, y] = to_process.front();
            to_process.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (years_left[A[nx][ny] - 1] > 0) {
                    years_left[A[nx][ny] - 1]--;
                    pq.push({-A[nx][ny], {nx, ny}});
                }
            }
        }

        cout << initial_area - years_left[abs(neg_elevation) - 1] << endl;
    }

    return 0;
}