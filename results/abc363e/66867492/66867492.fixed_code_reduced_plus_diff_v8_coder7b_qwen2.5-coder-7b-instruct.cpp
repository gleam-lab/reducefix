#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Init {
    Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int result[H * W];

    for (int level = 1; level <= Y; ++level) {
        int count = H * W;
        
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] <= level) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        --count;
                        
                        for (const auto& dir : directions) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            
                            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= level) {
                                q.emplace(nx, ny);
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        
        result[level - 1] = count;
    }

    for (int i = 0; i < Y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}