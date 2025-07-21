#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MOD 1000000007
int h, w, y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
    queue<pair<int, int>> q;
    for(int i = 0; i < w; i++) {
        if(grid[0][i] > 0) q.push({0, i});
        if(grid[h - 1][i] > 0) q.push({h - 1, i});
        visited[0][i] = visited[h - 1][i] = true;
    }
    for(int i = 1; i < h - 1; i++) {
        if(grid[i][0] > 0) q.push({i, 0});
        if(grid[i][w - 1] > 0) q.push({i, w - 1});
        visited[i][0] = visited[i][w - 1] = true;
    }

    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int remaining_area = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!visited[i][j]) remaining_area++;
        }
    }

    for(int year = 1; year <= y; year++) {
        int sinking_area = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(visited[i][j] && grid[i][j] <= year) {
                    sinking_area++;
                    visited[i][j] = false;
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > year) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        cout << remaining_area - sinking_area << '\n';
    }
}

int main() {
    cin >> h >> w >> y;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    solve();
    return 0;
}