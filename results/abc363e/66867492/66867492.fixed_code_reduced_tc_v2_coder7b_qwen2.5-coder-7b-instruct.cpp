#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Init {
    Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); }
} init;

typedef int64_t i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pqg;

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vvi A(H, vi(W));
    vvi used(H, vi(W));
    cin >> A;

    pqg pq;
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W - 1], i, W - 1});
        used[i][0] = 1;
        used[i][W - 1] = 1;
    }
    for (int i = 1; i < W - 1; ++i) {
        pq.push({A[0][i], 0, i});
        pq.push({A[H - 1][i], H - 1, i});
        used[0][i] = 1;
        used[H - 1][i] = 1;
    }

    int ans = H * W;
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (int i = 1; i <= Y; ++i) {
        while (!pq.empty() && pq.top()[0] <= i) {
            auto [height, y, x] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || used[ny][nx]) continue;
                if (chmax(used[ny][nx], 1)) {
                    pq.push({A[ny][nx], ny, nx});
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}