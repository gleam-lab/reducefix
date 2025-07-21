#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Add border cells to priority queue
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) {
            pq.emplace(A[i][0], i, 0);
            visited[i][0] = true;
        }
        if (!visited[i][W-1]) {
            pq.emplace(A[i][W-1], i, W-1);
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!visited[0][j]) {
            pq.emplace(A[0][j], 0, j);
            visited[0][j] = true;
        }
        if (!visited[H-1][j]) {
            pq.emplace(A[H-1][j], H-1, j);
            visited[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y + 1, remaining);
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [height, i, j] = pq.top();
            pq.pop();
            remaining--;
            
            const int dx[] = {0, 1, 0, -1};
            const int dy[] = {1, 0, -1, 0};
            
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        result[year] = remaining;
    }
    
    for (int year = 1; year <= Y; ++year) {
        cout << result[year] << '\n';
    }
    
    return 0;
}