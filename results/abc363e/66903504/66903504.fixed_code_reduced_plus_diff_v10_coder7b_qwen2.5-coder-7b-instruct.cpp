#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, m, q;

struct cmp {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    }
};

void bfs(int h) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] <= h) {
                pq.push({grid[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }
    
    int cnt = 0;
    while (!pq.empty()) {
        auto [height, pos] = pq.top(); pq.pop();
        cnt++;
        int x = pos.first, y = pos.second;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] <= height) {
                pq.push({grid[nx][ny], {nx, ny}});
                visited[nx][ny] = true;
            }
        }
    }
    
    cout << n * m - cnt << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> q;
    grid.resize(n, vector<int>(m)), visited.resize(n, vector<bool>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    sort(grid.begin(), grid.end());
    vector<int> heights(q);
    for (int i = 0; i < q; ++i) heights[i] = grid[i];
    heights.erase(unique(heights.begin(), heights.end()), heights.end());
    
    for (auto h : heights) bfs(h);
    
    return 0;
}