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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the priority queue with all border cells
    for (int i = 0; i < H; ++i) {
        if (!sunk[i][0]) {
            pq.push({A[i][0], {i, 0}});
            sunk[i][0] = true;
        }
        if (W > 1 && !sunk[i][W-1]) {
            pq.push({A[i][W-1], {i, W-1}});
            sunk[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!sunk[0][j]) {
            pq.push({A[0][j], {0, j}});
            sunk[0][j] = true;
        }
        if (H > 1 && !sunk[H-1][j]) {
            pq.push({A[H-1][j], {H-1, j}});
            sunk[H-1][j] = true;
        }
    }

    int ans = H * W;
    vector<int> res(Y);
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int x = current.second.first;
            int y = current.second.second;
            --ans;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    sunk[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        res[year-1] = ans;
    }

    for (int year = 1; year <= Y; ++year) {
        cout << res[year-1] << '\n';
    }

    return 0;
}