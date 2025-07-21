#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    int ans = H * W;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    vector<queue<pair<int,int>>> queues(100002); // Sea level can be up to 1e5

    // Initialize boundary cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                sunk[i][j] = true;
                queues[A[i][j]].emplace(i, j);
                ans--;
            }
        }
    }

    for (int y = 1; y <= Y; y++) {
        while (!queues[y].empty()) {
            auto [i, j] = queues[y].front();
            queues[y].pop();
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    if (A[ni][nj] <= y) {
                        sunk[ni][nj] = true;
                        queues[y].emplace(ni, nj);
                        ans--;
                    } else {
                        sunk[ni][nj] = true;
                        queues[A[ni][nj]].emplace(ni, nj);
                        ans--;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}