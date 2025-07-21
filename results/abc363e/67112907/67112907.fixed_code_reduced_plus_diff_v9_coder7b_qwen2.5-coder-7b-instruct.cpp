#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];

struct Point {
    int h, x, y;
    bool operator<(const Point &other) const {
        return h > other.h;
    }
};

void bfs(int sea_level) {
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Point> pq;
    
    // Collect all cells above the current sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= sea_level) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int count = 0;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                pq.push({A[nx][ny], nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    
    cout << H * W - count << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 1; i <= Y; ++i) {
        bfs(i);
    }
    
    return 0;
}