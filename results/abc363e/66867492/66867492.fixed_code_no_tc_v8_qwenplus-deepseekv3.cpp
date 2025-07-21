#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto &row : A) {
        for (auto &cell : row) {
            cin >> cell;
        }
    }
    
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    
    // Push border cells
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], {i, 0}});
        sunk[i][0] = true;
        if (W > 1) {
            pq.push({A[i][W-1], {i, W-1}});
            sunk[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        pq.push({A[0][j], {0, j}});
        sunk[0][j] = true;
        if (H > 1) {
            pq.push({A[H-1][j], {H-1, j}});
            sunk[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int h = current.second.first;
            int w = current.second.second;
            
            remaining--;
            
            for (int d = 0; d < 4; ++d) {
                int nh = h + dy[d];
                int nw = w + dx[d];
                
                if (nh >= 0 && nh < H && nw >= 0 && nw < W && !sunk[nh][nw]) {
                    sunk[nh][nw] = true;
                    pq.push({A[nh][nw], {nh, nw}});
                }
            }
        }
        cout << remaining << '\n';
    }
}