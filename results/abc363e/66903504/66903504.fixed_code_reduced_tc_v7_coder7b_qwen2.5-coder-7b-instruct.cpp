#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> grid(H, vector<int>(W, 0));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            pq.push({A[i][j], {i, j}});
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<int> areas(Y + 1, 0);
    while(!pq.empty()) {
        auto [level, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;
        if(visited[x][y]) continue;
        visited[x][y] = true;
        ++areas[level];

        for(auto [dx, dy] : {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= level) {
                pq.push({A[nx][ny], {nx, ny}});
            }
        }
    }

    reverse(areas.begin() + 1, areas.end());
    for(int i = 1; i <= Y; ++i) {
        cout << (H * W - areas[i]) << '\n';
    }

    return 0;
}