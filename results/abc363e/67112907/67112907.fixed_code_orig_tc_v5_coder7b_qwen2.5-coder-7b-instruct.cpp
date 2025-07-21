#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Section {
    int h, x, y;
    bool operator<(const Section &other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Section> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Initialize the priority queue with sections above the initial sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > 0) {
                pq.push({A[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int totalArea = H * W;
    for (int t = 1; t <= Y; ++t) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > t) {
                break;
            }
            pq.pop();
            totalArea--;
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= t) {
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        cout << totalArea << '\n';
    }

    return 0;
}