#include<bits/stdc++.h>
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
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    int remaining = H * W;

    // Initialize the queue with border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    vector<int> result(Y + 1, remaining);
    int current_level = 1;

    while (current_level <= Y && !pq.empty()) {
        while (!pq.empty() && pq.top().first <= current_level) {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;

            remaining--;

            // Check four directions
            const int dx[] = {-1, 1, 0, 0};
            const int dy[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    sunk[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        result[current_level] = remaining;
        current_level++;
    }

    // Fill remaining years if the sea level exceeds the highest elevation
    for (int y = 1; y <= Y; ++y) {
        if (y < result.size()) {
            cout << result[y] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}