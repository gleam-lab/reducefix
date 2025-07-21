#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                submerged[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> ans(Y + 1, 0); // ans[y] stores the answer for year y
    ans[0] = remaining;

    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            auto current = pq.top();
            pq.pop();
            int i = current.second.first;
            int j = current.second.second;
            remaining--;

            // Check adjacent cells
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                    submerged[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        ans[y] = remaining;
    }

    for (int y = 1; y <= Y; ++y) {
        cout << ans[y] << "\n";
    }

    return 0;
}