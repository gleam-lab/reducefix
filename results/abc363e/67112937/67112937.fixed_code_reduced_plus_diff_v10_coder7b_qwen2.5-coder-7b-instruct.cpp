#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int MAXN = 1005;

int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
    int h, x, y;
    bool operator<(const Node& other) const {
        return h > other.h;
    }
};

void bfs(int sea_level) {
    memset(vis, false, sizeof(vis));
    priority_queue<Node> pq;
    
    // Push all boundary nodes to the priority queue
    for (int i = 0; i < H; ++i) {
        if (A[i][0] <= sea_level) pq.push({A[i][0], i, 0});
        if (A[i][W - 1] <= sea_level) pq.push({A[i][W - 1], i, W - 1});
    }
    for (int j = 1; j < W - 1; ++j) {
        if (A[0][j] <= sea_level) pq.push({A[0][j], 0, j});
        if (A[H - 1][j] <= sea_level) pq.push({A[H - 1][j], H - 1, j});
    }
    
    while (!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] <= sea_level && !vis[nx][ny]) {
                pq.push({A[nx][ny], nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<int> results(Y);
    
    for (int year = 0; year < Y; ++year) {
        bfs(year);
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j]) {
                    ++count;
                }
            }
        }
        results[year] = count;
    }
    
    for (int res : results) {
        cout << res << '\n';
    }
    
    return 0;
}