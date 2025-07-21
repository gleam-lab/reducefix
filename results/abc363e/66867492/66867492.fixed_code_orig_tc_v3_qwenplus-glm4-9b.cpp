#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> used;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void update(int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (A[ny][nx] > Y + 1) continue;
            if (used[ny][nx]) continue;
            used[ny][nx] = 1;
            pq.push({ A[ny][nx], {ny, nx} });
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    used.resize(H, vector<bool>(W, false));
    pq.resize(H * W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                used[i][j] = true;
                pq.push({ A[i][j], {i, j} });
            }
        }
    }

    int remaining = H * W;
    while (!pq.empty()) {
        auto [elevation, pos] = pq.top();
        pq.pop();
        int x = pos.first, y = pos.second;
        if (elevation <= Y) {
            remaining--;
            update(x, y);
        }
    }

    cout << remaining << endl;

    return 0;
}