#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> removed;
vector<vector<bool>> is_boundary;
vector<vector<int>> min_neighbor_height;

// This function performs multi-source BFS from the sea-connected regions
void bfs(int current_year, queue<pair<int, int>>& q) {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !removed[nx][ny]) {
                // If this cell can be submerged now
                if (A[nx][ny] <= current_year) {
                    removed[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    removed.assign(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Mark boundary cells as removed and add to queue
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            removed[i][j] = true;
            q.push({i, j});
        }
    }

    // Run BFS to flood as much as possible initially
    queue<pair<int, int>> temp_q = q;
    bfs(Y, temp_q);

    // Reset removed cells for actual simulation
    removed.assign(H, vector<bool>(W, false));
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            removed[i][j] = true;
            q.push({i, j});
        }
    }

    // Prepare map of height -> cells at that height
    vector<vector<int>> height_cells(Y+2);
    rep(i, H) rep(j, W) {
        if (A[i][j] <= Y)
            height_cells[A[i][j]].push_back(i * W + j);
    }

    // Process year by year
    for (int year = 1; year <= Y; ++year) {
        // Add cells with this height to the queue if they're not already removed
        for (int idx : height_cells[year]) {
            int i = idx / W;
            int j = idx % W;
            if (!removed[i][j]) {
                removed[i][j] = true;
                q.push({i, j});
            }
        }

        // Run BFS to flood connected areas
        queue<pair<int, int>> curr_year_q = q;
        q = queue<pair<int, int>>();
        bfs(year, curr_year_q);

        // Count remaining land
        int count = 0;
        rep(i, H) rep(j, W) count += !removed[i][j];
        cout << count << "\n";
    }
}