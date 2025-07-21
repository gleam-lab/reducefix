#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9 + 10;

struct Point {
    int x, y, height;
    bool operator<(const Point& other) const {
        return height < other.height;
    }
};

vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));

void bfs(vector<vector<int>>& A, int sea_level) {
    int n = A.size();
    int m = A[0].size();
    vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && A[i][j] <= sea_level) {
                queue<Point> q;
                q.emplace(i, j, A[i][j]);
                visited[i][j] = true;
                
                while (!q.empty()) {
                    Point p = q.front();
                    q.pop();
                    
                    for (auto& dir : directions) {
                        int ni = p.x + dir.first;
                        int nj = p.y + dir.second;
                        
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && A[ni][nj] <= sea_level) {
                            visited[ni][nj] = true;
                            q.emplace(ni, nj, A[ni][nj]);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    priority_queue<Point> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(i, 0, A[i][0]);
        pq.emplace(i, W - 1, A[i][W - 1]);
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(0, j, A[0][j]);
        pq.emplace(H - 1, j, A[H - 1][j]);
    }
    
    int total_area = H * W;
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().height <= year) {
            Point p = pq.top();
            pq.pop();
            
            if (visited[p.x][p.y]) continue;
            
            visited[p.x][p.y] = true;
            total_area--;
            
            vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (auto& dir : directions) {
                int ni = p.x + dir.first;
                int nj = p.y + dir.second;
                
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] <= year) {
                    pq.emplace(ni, nj, A[ni][nj]);
                }
            }
        }
        
        cout << total_area << endl;
    }
    
    return 0;
}