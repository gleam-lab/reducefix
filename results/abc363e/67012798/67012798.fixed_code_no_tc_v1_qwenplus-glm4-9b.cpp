#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

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

    // Initialize the sea and find initial low areas
    vector<vector<bool>> sinkable(H, vector<bool>(W, false));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || (A[i][j] <= 0)) {
                sinkable[i][j] = true;
            }
        }
    }

    // Perform BFS to find all areas that will eventually sink
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (sinkable[i][j]) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && sinkable[nx][ny]) {
                sinkable[nx][ny] = false;
                q.push({nx, ny});
            }
        }
    }

    // Count initial low areas
    int low_areas = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (sinkable[i][j]) {
                low_areas++;
            }
        }
    }

    // Calculate remaining area after Y years
    for (int i = 1; i <= Y; i++) {
        int remaining = 0;
        for (int j = 0; j < W; j++) { // We only need to check the first column
            remaining += H - 1 - j;
        }
        cout << (H * W - remaining - low_areas) << endl;
        low_areas -= min(low_areas, (int)i);
    }

    return 0;
}