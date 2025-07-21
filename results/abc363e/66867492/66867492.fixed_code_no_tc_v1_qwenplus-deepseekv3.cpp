#include <bits/stdc++.h>
using namespace std;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vvi used(H, vi(W, 0));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], {i, 0}});
        used[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W - 1], {i, W - 1}});
            used[i][W - 1] = 1;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.push({A[0][j], {0, j}});
        used[0][j] = 1;
        if (H > 1) {
            pq.push({A[H - 1][j], {H - 1, j}});
            used[H - 1][j] = 1;
        }
    }

    int ans = H * W;
    vector<pii> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int x = current.second.first;
            int y = current.second.second;
            if (A[x][y] > year) continue; // Already processed or not sinking yet
            ans--;

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !used[nx][ny]) {
                    used[nx][ny] = 1;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}