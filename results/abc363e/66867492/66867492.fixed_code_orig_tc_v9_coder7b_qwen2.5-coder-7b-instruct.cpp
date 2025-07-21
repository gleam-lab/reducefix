#include <bits/stdc++.h>
using namespace std;

struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } } init;

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> used(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W - 1], make_pair(i, W - 1));
        used[i][0] = true;
        used[i][W - 1] = true;
    }

    for (int i = 0; i < W; ++i) {
        pq.emplace(A[0][i], make_pair(0, i));
        pq.emplace(A[H - 1][i], make_pair(H - 1, i));
        used[0][i] = true;
        used[H - 1][i] = true;
    }

    vector<int> results(Y);
    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    for (int y = 0; y < Y; ++y) {
        while (!pq.empty() && pq.top().first <= y + 1) {
            auto [height, pos] = pq.top(); pq.pop();
            --ans;
            for (int k = 0; k < 4; ++k) {
                int ny = pos.first + dy[k], nx = pos.second + dx[k];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || used[ny][nx]) continue;
                used[ny][nx] = true;
                pq.emplace(A[ny][nx], make_pair(ny, nx));
            }
        }
        results[y] = ans;
    }

    for (const auto& res : results) {
        cout << res << endl;
    }

    return 0;
}