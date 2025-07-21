#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int total = H * W;
    vector<vector<bool>> ocean(H, vector<bool>(W, false));
    vector<vector<int>> timeline(Y + 2);
    
    // Mark border cells
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                timeline[A[i][j]].push_back(i * W + j);
                ocean[i][j] = true;
            }
        }
    }

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        for (int pos : timeline[year]) {
            int i = pos / W;
            int j = pos % W;
            if (!ocean[i][j]) {
                ocean[i][j] = true;
                q.emplace(i, j);
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            total--;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !ocean[nx][ny]) {
                    int h = A[nx][ny];
                    if (h <= year) {
                        ocean[nx][ny] = true;
                        q.emplace(nx, ny);
                    } else {
                        timeline[h].push_back(nx * W + ny);
                    }
                }
            }
        }

        cout << total << "\n";
    }

    return 0;
}