#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> p, sz;
    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    dsu uf(H * W);
    vector<vector<bool>> visited(H, vector<bool>(W));
    const vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    auto get_index = [&](int x, int y) { return x * W + y; };
    
    for (int h = 1; h <= Y; ++h) {
        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] > h) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        auto [cx, cy] = q.front();
                        q.pop();
                        
                        for (auto& [dx, dy] : dirs) {
                            int nx = cx + dx, ny = cy + dy;
                            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                            if (A[nx][ny] > h && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.emplace(nx, ny);
                                uf.unite(get_index(cx, cy), get_index(nx, ny));
                            }
                        }
                    }
                    
                    cnt++;
                }
            }
        }
        
        int total_area = H * W - cnt * uf.sz[uf.find(get_index(0, 0))];
        cout << total_area << '\n';
    }
    
    return 0;
}