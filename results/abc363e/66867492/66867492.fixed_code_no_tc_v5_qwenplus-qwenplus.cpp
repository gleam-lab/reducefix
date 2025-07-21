#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using Pi = pair<int, int>;
using pq_type = priority_queue<Pi, vector<Pi>, function<bool(Pi,Pi)>>;

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
    vvi A(H, vi(W));
    for (auto &row : A) cin >> row;

    // Priority queue to process cells in increasing order of elevation
    auto cmp = [&](Pi a, Pi b) { return A[a.first][a.second] > A[b.first][b.second]; };
    priority_queue<Pi, vector<Pi>, decltype(cmp)> pq(cmp);

    vvi used(H, vi(W));
    int ans = H * W;

    // Initialize the queue with the border cells
    for (int i = 0; i < H; ++i) {
        for (int j : {0, W - 1}) {
            if (!used[i][j]) {
                used[i][j] = true;
                pq.emplace(i, j);
            }
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        for (int i : {0, H - 1}) {
            if (!used[i][j]) {
                used[i][j] = true;
                pq.emplace(i, j);
            }
        }
    }

    vi result(Y + 2); // Store results for each year
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && A[pq.top().first][pq.top().second] <= year) {
            auto [x, y] = pq.top(); pq.pop();
            --ans;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < H && ny < W && !used[nx][ny]) {
                    used[nx][ny] = true;
                    pq.emplace(nx, ny);
                }
            }
        }
        result[year] = ans;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << '\n';
    }
}