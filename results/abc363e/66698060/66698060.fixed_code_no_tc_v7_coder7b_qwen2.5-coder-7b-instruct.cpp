#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main(){
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> q;

    auto valid = [&](int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w && !visited[x][y];
    };

    auto bfs = [&](int level) {
        int count = 0;
        q = {};
        rep(i, h) rep(j, w) if (!visited[i][j] && grid[i][j] > level) {
            q.push({i, j});
            visited[i][j] = true;
            ++count;
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            rep(d, 4) {
                int nx = x + dx[d], ny = y + dy[d];
                if (valid(nx, ny)) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    ++count;
                }
            }
        }

        return count;
    };

    vector<int> result(y);
    rep(i, y) result[y - 1 - i] = bfs(i);

    rep(i, y) cout << result[i] << endl;

    return 0;
}