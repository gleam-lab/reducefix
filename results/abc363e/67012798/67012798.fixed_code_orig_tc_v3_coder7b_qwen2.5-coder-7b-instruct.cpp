#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Priority queue to process sections based on their elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            pq.push({A[i][j], {i, j}});
        }
    }

    int remaining_area = H * W;

    for (int k = 1; k <= Y; k++) {
        while (!pq.empty() && pq.top().first <= k) {
            auto [height, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            if (visited[x][y]) continue;
            visited[x][y] = true;

            remaining_area--;
        }

        cout << remaining_area << endl;
    }

    return 0;
}