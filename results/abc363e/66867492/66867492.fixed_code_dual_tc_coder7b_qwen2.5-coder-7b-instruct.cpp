#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;
const int MAXN = 1005;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    cin >> A;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> used(H, vector<bool>(W, false));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], {i, 0});
        pq.emplace(A[i][W - 1], {i, W - 1});
        used[i][0] = true;
        used[i][W - 1] = true;
    }

    for (int i = 1; i < W - 1; ++i) {
        pq.emplace(A[0][i], {0, i});
        pq.emplace(A[H - 1][i], {H - 1, i});
        used[0][i] = true;
        used[H - 1][i] = true;
    }

    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            auto [height, pos] = pq.top();
            pq.pop();
            --ans;

            for (int d = 0; d < 4; ++d) {
                int ny = pos.first + dy[d], nx = pos.second + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (!used[ny][nx] && A[ny][nx] > y) {
                    used[ny][nx] = true;
                    pq.emplace(A[ny][nx], {ny, nx});
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}