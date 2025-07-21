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

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Push all border cells
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) {
            pq.push({A[i][0], {i, 0}});
            visited[i][0] = true;
        }
        if (!visited[i][W-1]) {
            pq.push({A[i][W-1], {i, W-1}});
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!visited[0][j]) {
            pq.push({A[0][j], {0, j}});
            visited[0][j] = true;
        }
        if (!visited[H-1][j]) {
            pq.push({A[H-1][j], {H-1, j}});
            visited[H-1][j] = true;
        }
    }

    int remaining = H * W;
    vector<int> res(Y);

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            remaining--;
            
            int i = current.second.first;
            int j = current.second.second;
            
            const int di[] = {-1, 1, 0, 0};
            const int dj[] = {0, 0, -1, 1};
            
            for (int d = 0; d < 4; ++d) {
                int ni = i + di[d];
                int nj = j + dj[d];
                
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        res[year-1] = remaining;
    }

    for (int y = 0; y < Y; ++y) {
        cout << res[y] << '\n';
    }

    return 0;
}