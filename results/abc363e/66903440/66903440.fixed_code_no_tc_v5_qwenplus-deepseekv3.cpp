#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the border sections
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y + 1, ans);
    int current_sea_level = 0;

    for (int y = 1; y <= Y; ++y) {
        current_sea_level = y;
        while (!pq.empty() && pq.top().first <= current_sea_level) {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            if (sunk[i][j]) {
                ans--;
                sunk[i][j] = false; // Mark to avoid reprocessing
                // Check adjacent cells
                const int dx[] = {1, 0, -1, 0};
                const int dy[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                        sunk[ni][nj] = true;
                        pq.push({A[ni][nj], {ni, nj}});
                    }
                }
            }
        }
        res[y] = ans;
    }

    for (int y = 1; y <= Y; ++y) {
        cout << res[y] << "\n";
    }

    return 0;
}