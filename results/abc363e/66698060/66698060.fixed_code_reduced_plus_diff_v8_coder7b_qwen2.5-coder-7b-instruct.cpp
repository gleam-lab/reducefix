#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

vector<vector<ll>> grid;
priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
vector<vector<bool>> visited;

void dfs(int x, int y, int sea_level) {
    stack<pair<int, int>> s;
    s.push({x, y});
    while (!s.empty()) {
        auto [cx, cy] = s.top();
        s.pop();
        if (visited[cx][cy]) continue;
        visited[cx][cy] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] <= sea_level && !visited[nx][ny]) {
                s.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll h, w, y;
    cin >> h >> w >> y;
    
    grid.resize(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> grid[i][j];
            pq.push({grid[i][j], {i, j}});
        }
    }
    
    visited.assign(h, vector<bool>(w, false));
    
    for (ll year = 1; year <= y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto [height, pos] = pq.top();
            pq.pop();
            if (visited[pos.first][pos.second]) continue;
            visited[pos.first][pos.second] = true;
            for (int k = 0; k < 4; ++k) {
                int nx = pos.first + dx[k], ny = pos.second + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }
        
        visited.assign(h, vector<bool>(w, false));
        dfs(0, 0, year);
        
        ll count = 0;
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (!visited[i][j]) ++count;
            }
        }
        
        cout << count << '\n';
    }
    
    return 0;
}