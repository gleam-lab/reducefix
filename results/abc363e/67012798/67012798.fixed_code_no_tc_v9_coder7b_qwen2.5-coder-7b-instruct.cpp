#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int level, int& remainingArea) {
    queue<pair<int, int>> q;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] > level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                remainingArea--;
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && A[nx][ny] <= level && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                remainingArea--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) 
        for(int j = 0; j < W; ++j) 
            cin >> A[i][j];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int totalArea = H * W;
    vector<int> result(Y);

    for(int level = 1; level <= Y; ++level) {
        bfs(A, visited, level, totalArea);
        result[level-1] = totalArea;
    }

    for(auto res : result) 
        cout << res << '\n';

    return 0;
}