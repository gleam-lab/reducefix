#include <bits/stdc++.h>
using namespace std;

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
    
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int,int>>, 
                   vector<pair<int, pair<int,int>>>, 
                   greater<pair<int, pair<int,int>>>> pq;
    
    // Push boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!sunk[i][0]) {
            pq.push({A[i][0], {i, 0}});
            sunk[i][0] = true;
        }
        if (!sunk[i][W-1]) {
            pq.push({A[i][W-1], {i, W-1}});
            sunk[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!sunk[0][j]) {
            pq.push({A[0][j], {0, j}});
            sunk[0][j] = true;
        }
        if (!sunk[H-1][j]) {
            pq.push({A[H-1][j], {H-1, j}});
            sunk[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y);
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            remaining--;
            
            int y = current.second.first;
            int x = current.second.second;
            
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny >= 0 && ny < H && nx >= 0 && nx < W && !sunk[ny][nx]) {
                    sunk[ny][nx] = true;
                    pq.push({A[ny][nx], {ny, nx}});
                }
            }
        }
        result[year-1] = remaining;
    }
    
    for (int i = 0; i < Y; ++i) {
        cout << result[i] << '\n';
    }
    
    return 0;
}