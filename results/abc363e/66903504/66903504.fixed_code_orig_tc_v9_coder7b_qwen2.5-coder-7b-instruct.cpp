#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

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

    vector<vector<bool>> F(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> Q(Y + 1);
    
    // Mark boundary cells as initially flooded
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                Q[0].push({i, j});
            }
        }
    }

    // Process each sea level rise
    for (int y = 0; y <= Y; ++y) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();
            
            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    if (F[ni][nj]) {
                        F[ni][nj] = false;
                        Q[y].push({ni, nj});
                    }
                }
            }
        }
        
        // Count the number of cells above water
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (F[i][j] && A[i][j] > y) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }

    return 0;
}