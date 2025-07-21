#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const int INF = 1e9;

struct Cell {
    int height, x, y;
    Cell(int h, int xi, int yi) : height(h), x(xi), y(yi) {}
    bool operator>(const Cell& other) const { return height > other.height; }
};

int main() {
    ll h, w, y; cin >> h >> w >> y;
    vector<vector<ll>> grid(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    priority_queue<Cell> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    rep(i, h) {
        pq.push(Cell(grid[i][0], i, 0));
        visited[i][0] = true;
        pq.push(Cell(grid[i][w-1], i, w-1));
        visited[i][w-1] = true;
    }
    for(int j = 1; j < w-1; j++) {
        pq.push(Cell(grid[0][j], 0, j));
        visited[0][j] = true;
        pq.push(Cell(grid[h-1][j], h-1, j));
        visited[h-1][j] = true;
    }

    int ans = h * w;
    rep(_, y) {
        while(!pq.empty() && pq.top().height <= _) {
            auto [height, x, y] = pq.top();
            pq.pop();
            --ans;
            rep(k, 4) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                    pq.push(Cell(grid[nx][ny], nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        cout << ans << '\n';
    }
}