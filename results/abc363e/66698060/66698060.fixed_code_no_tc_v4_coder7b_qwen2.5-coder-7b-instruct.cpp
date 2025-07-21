#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const int N = 1010;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    vector<vector<int>> visited(h, vector<int>(w, 0));
    vector<pair<int, pair<int, int>>> pq;

    auto valid = [&](int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w && !visited[x][y];
    };

    auto bfs = [&](int level) {
        queue<pair<int, int>> q;
        rep(i, h) rep(j, w) if (grid[i][j] > level) {
            q.push({i, j});
            visited[i][j] = 1;
        }

        int count = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            count++;
            rep(k, 4) {
                int nx = x + dx[k], ny = y + dy[k];
                if (valid(nx, ny)) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        return count;
    };

    rep(i, y) {
        int level = i + 1;
        int area = bfs(level);
        cout << area << '\n';
    }

    return 0;
}