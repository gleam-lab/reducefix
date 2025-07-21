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

    int ans = H * W;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the priority queue with border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    vector<int> res(Y + 1, 0);
    res[0] = ans;
    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            auto current = pq.top();
            pq.pop();
            int i = current.second.first;
            int j = current.second.second;
            if (!sunk[i][j]) continue;
            ans--;
            // Check adjacent cells
            if (i > 0 && !sunk[i - 1][j]) {
                sunk[i - 1][j] = true;
                pq.push({A[i - 1][j], {i - 1, j}});
            }
            if (i < H - 1 && !sunk[i + 1][j]) {
                sunk[i + 1][j] = true;
                pq.push({A[i + 1][j], {i + 1, j}});
            }
            if (j > 0 && !sunk[i][j - 1]) {
                sunk[i][j - 1] = true;
                pq.push({A[i][j - 1], {i, j - 1}});
            }
            if (j < W - 1 && !sunk[i][j + 1]) {
                sunk[i][j + 1] = true;
                pq.push({A[i][j + 1], {i, j + 1}});
            }
        }
        res[y] = ans;
    }

    for (int y = 1; y <= Y; ++y) {
        cout << res[y] << '\n';
    }

    return 0;
}