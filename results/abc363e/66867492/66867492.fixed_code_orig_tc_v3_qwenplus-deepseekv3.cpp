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
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    vvi used(H, vi(W, 0));

    // Initialize the priority queue with border cells
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], {i, 0}});
        used[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W-1], {i, W-1}});
            used[i][W-1] = 1;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        pq.push({A[0][j], {0, j}});
        used[0][j] = 1;
        if (H > 1) {
            pq.push({A[H-1][j], {H-1, j}});
            used[H-1][j] = 1;
        }
    }

    int ans = H * W;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            auto current = pq.top();
            pq.pop();
            int i = current.second.first;
            int j = current.second.second;
            if (used[i][j] == 2) continue; // Already processed
            used[i][j] = 2;
            --ans;
            for (auto dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !used[ni][nj]) {
                    used[ni][nj] = 1;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}