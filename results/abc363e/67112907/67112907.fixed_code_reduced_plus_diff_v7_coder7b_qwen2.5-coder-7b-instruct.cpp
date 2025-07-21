#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int parent[MAXN * MAXN];
int rank_[MAXN * MAXN];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank_[i] = 0;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    if (rank_[pu] > rank_[pv]) {
        parent[pv] = pu;
    } else {
        parent[pu] = pv;
        if (rank_[pu] == rank_[pv]) {
            rank_[pv]++;
        }
    }
}

int countComponents(int n, vector<vector<int>>& grid) {
    init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) continue;
            if (i > 0 && grid[i - 1][j] == 0) unite(i * n + j, (i - 1) * n + j);
            if (j > 0 && grid[i][j - 1] == 0) unite(i * n + j, i * n + (j - 1));
        }
    }
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) continue;
            seen.insert(find(i * n + j));
        }
    }
    return seen.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int k = 0; k < Y; ++k) {
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<pair<int, int>> q;
        
        // Initialize the queue with cells above the current sea level
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > k) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Perform BFS to mark all connected components above the current sea level
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx * dy != 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > k) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }

        // Count the number of connected components above the current sea level
        int components = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > k && !visited[i][j]) {
                    components++;
                    dfs(A, visited, i, j, k);
                }
            }
        }

        cout << components << '\n';
    }

    return 0;
}

void dfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int x, int y, int k) {
    static const int dx[] = {0, 0, 1, -1};
    static const int dy[] = {1, -1, 0, 0};

    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && A[nx][ny] > k && !visited[nx][ny]) {
            dfs(A, visited, nx, ny, k);
        }
    }
}