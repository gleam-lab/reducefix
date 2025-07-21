#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using Pii = pair<int, int>;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    int max_elevation = 0;
    rep(i, H) rep(j, W) {
        cin >> A[i][j];
        max_elevation = max(max_elevation, A[i][j]);
    }

    // Create a map of elevation -> list of cells with that elevation
    vector<vector<Pii>> elev_map(max_elevation + 2);  // up to Y+1
    rep(i, H) rep(j, W) {
        elev_map[A[i][j]].push_back({i, j});
    }

    vector<vector<bool>> is_submerged(H, vector<bool>(W, false));
    int remaining = H * W;

    // For each year, simulate the submersion process
    vector<vector<queue<Pii>>> q_by_level(Y + 2);
    
    // Initialize boundaries
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            q_by_level[A[i][j]].push({i, j});
            is_submerged[i][j] = true;
            remaining--;
        }
    }

    for (int y = 1; y <= Y; ++y) {
        queue<Pii> current_q;
        
        // Move from yearly queue to working queue
        while (!q_by_level[y].empty()) {
            current_q.push(q_by_level[y].front());
            q_by_level[y].pop();
        }

        while (!current_q.empty()) {
            auto [x, y_pos] = current_q.front();
            current_q.pop();

            rep(d, 4) {
                int nx = x + dx[d];
                int ny = y_pos + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !is_submerged[nx][ny]) {
                    int height = A[nx][ny];
                    if (height <= y) {
                        is_submerged[nx][ny] = true;
                        remaining--;
                        current_q.push({nx, ny});
                    } else {
                        // This cell will be submerged in the future
                        q_by_level[height].push({nx, ny});
                        is_submerged[nx][ny] = true;
                        remaining--;
                    }
                }
            }
        }

        cout << remaining << "\n";
    }

    return 0;
}