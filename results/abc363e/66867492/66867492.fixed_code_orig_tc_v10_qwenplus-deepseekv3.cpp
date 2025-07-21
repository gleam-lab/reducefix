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
    
    vector<vector<bool>> used(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    // Push border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!used[i][0]) {
            pq.emplace(A[i][0], i, 0);
            used[i][0] = true;
        }
        if (!used[i][W-1]) {
            pq.emplace(A[i][W-1], i, W-1);
            used[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!used[0][j]) {
            pq.emplace(A[0][j], 0, j);
            used[0][j] = true;
        }
        if (!used[H-1][j]) {
            pq.emplace(A[H-1][j], H-1, j);
            used[H-1][j] = true;
        }
    }
    
    int ans = H * W;
    vector<int> res(Y + 1, ans); // res[0] is initial state
    
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dy[d];
                int nj = j + dx[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        res[year] = ans;
    }
    
    for (int i = 1; i <= Y; ++i) {
        cout << res[i] << '\n';
    }
    
    return 0;
}