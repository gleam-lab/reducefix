#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)

struct Cell {
    int h, x, y;
    bool operator<(const Cell &o) const {
        return h > o.h;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    priority_queue<Cell> pq;
    vector<vector<bool>> seen(H, vector<bool>(W));
    rep(i, H) rep(j, W) {
        if(A[i][j] > A[0][0]) continue;
        pq.push({A[i][j], i, j});
        seen[i][j] = true;
    }

    vector<vector<bool>> visited(H, vector<bool>(W));
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
    while(!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();
        visited[x][y] = true;
        for(auto &[dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny] || A[nx][ny] <= h) continue;
            pq.push({A[nx][ny], nx, ny});
            visited[nx][ny] = true;
        }
    }

    vector<vector<int>> res(Y+1, vector<int>(H*W+1));
    res[0][0] = H*W;
    for(int t = 1; t <= Y; ++t) {
        for(auto &[h, x, y] : pq) {
            if(h > t) break;
            res[t][h]++;
        }
        for(auto &[h, x, y] : pq) {
            if(h <= t) break;
            res[t][h]--;
        }
        for(int h = 1; h <= 1e5; ++h) res[t][h] += res[t][h-1];
    }

    for(int t = 1; t <= Y; ++t) cout << res[t][0] << '\n';

    return 0;
}