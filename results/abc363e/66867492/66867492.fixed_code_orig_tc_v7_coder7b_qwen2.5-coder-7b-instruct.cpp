#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } } init;

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (A[i][j] > 0) {
                used[i][j] = true;
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (used[i][j]) {
                pq.emplace(A[i][j], make_pair(i, j));
            }
        }
    }

    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            auto [height, pos] = pq.top(); pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = pos.first + dy[d], nx = pos.second + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (!used[ny][nx] && A[ny][nx] <= y) {
                    used[ny][nx] = true;
                    pq.emplace(y, make_pair(ny, nx));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}