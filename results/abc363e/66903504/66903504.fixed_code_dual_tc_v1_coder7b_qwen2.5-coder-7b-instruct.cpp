#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int total_area = H * W;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> Q(Y + 1);

    // Initialize boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                Q[A[i][j]].push({i, j});
            }
        }
    }

    // Process each year
    for (int y = 1; y <= Y; ++y) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();
            total_area--;

            const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
            const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    Q[max(A[ni][nj], y)].push({ni, nj});
                }
            }
        }
        cout << total_area << endl;
    }

    return 0;
}