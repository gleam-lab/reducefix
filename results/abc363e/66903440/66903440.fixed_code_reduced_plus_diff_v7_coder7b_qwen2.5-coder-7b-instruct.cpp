#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> sea_level_area(Y + 1, vector<int>(H * W + 1, 0));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    function<void(int, int, int)> bfs = [&](int sx, int sy, int height) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        while(!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            sea_level_area[height][A[cx][cy]]++;
            for(auto [dx, dy] : directions) {
                int nx = cx + dx, ny = cy + dy;
                if(nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= height) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    };

    for(int h = 1; h <= Y; ++h) {
        fill(visited.begin(), visited.end(), false);
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if(!visited[i][j] && A[i][j] > h) {
                    bfs(i, j, h);
                }
            }
        }
        for(int a = 1; a <= H * W; ++a) {
            sea_level_area[h][a] += sea_level_area[h - 1][a];
        }
    }

    for(int h = 1; h <= Y; ++h) {
        cout << H * W - sea_level_area[h][H * W] << '\n';
    }

    return 0;
}