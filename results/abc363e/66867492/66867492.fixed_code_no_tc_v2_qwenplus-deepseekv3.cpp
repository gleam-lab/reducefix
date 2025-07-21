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
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    // Initialize the priority queue with boundary sections
    for (int i = 0; i < H; ++i) {
        if (!sunk[i][0]) {
            pq.push(make_tuple(A[i][0], i, 0));
            sunk[i][0] = true;
        }
        if (!sunk[i][W-1]) {
            pq.push(make_tuple(A[i][W-1], i, W-1));
            sunk[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!sunk[0][j]) {
            pq.push(make_tuple(A[0][j], 0, j));
            sunk[0][j] = true;
        }
        if (!sunk[H-1][j]) {
            pq.push(make_tuple(A[H-1][j], H-1, j));
            sunk[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y + 1, remaining);
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            remaining--;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dy[d];
                int nj = j + dx[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    pq.push(make_tuple(A[ni][nj], ni, nj));
                    sunk[ni][nj] = true;
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