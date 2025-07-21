#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Initialize used matrix and priority queue
    vector<vector<bool>> used(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Push all boundary cells into the priority queue
    auto add = [&](int i, int j) {
        used[i][j] = true;
        pq.emplace(A[i][j], i, j);
    };

    rep(i, H) {
        add(i, 0);
        if (W > 1) add(i, W - 1);
    }
    rep3(j, 1, W - 1) {
        add(0, j);
        if (H > 1) add(H - 1, j);
    }

    int remaining = H * W;
    vector<int> ans(Y + 1);

    rep3(y, 1, Y + 1) {
        while (!pq.empty() && get<0>(pq.top()) <= y) {
            auto [val, i, j] = pq.top();
            pq.pop();
            --remaining;

            const int di[] = {-1, 0, 1, 0};
            const int dj[] = {0, 1, 0, -1};
            rep(d, 4) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        ans[y] = remaining;
    }

    rep3(y, 1, Y + 1) cout << ans[y] << "\n";
}