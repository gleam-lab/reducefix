#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the boundary sections
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    int current_area = H * W;
    vector<int> result(Y + 1, current_area);

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int year = top.first;
        int x = top.second.first;
        int y = top.second.second;

        if (year > Y) {
            break;
        }

        current_area--;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                sunk[nx][ny] = true;
                pq.push({A[nx][ny], {nx, ny}});
            }
        }

        if (year <= Y) {
            result[year] = current_area;
        }
    }

    // Fill in the results for years beyond the last processed year
    for (int i = 1; i <= Y; i++) {
        if (result[i] == 0) {
            result[i] = result[i - 1];
        }
    }

    // Ensure the results account for all years correctly
    for (int i = 1; i <= Y; i++) {
        if (result[i] == H * W) {
            result[i] = result[i - 1];
        }
    }

    // Output the results for each year from 1 to Y
    for (int i = 1; i <= Y; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}