#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int>> q;

void bfs(int sea_level) {
    while(!q.empty()) q.pop();
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(A[i][j] > sea_level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if(nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] > sea_level && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W >> Y;
    for(int i = 0; i < H; ++i) 
        for(int j = 0; j < W; ++j) 
            cin >> A[i][j];
    
    for(int i = 1; i <= Y; ++i) {
        memset(visited, false, sizeof(visited));
        bfs(i);
        int cnt = 0;
        for(int i = 0; i < H; ++i) 
            for(int j = 0; j < W; ++j) 
                if(visited[i][j]) ++cnt;
        cout << cnt << '\n';
    }
    return 0;
}