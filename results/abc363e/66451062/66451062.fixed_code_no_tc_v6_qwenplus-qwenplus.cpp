#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int H = 1010, W = 1010;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int h, w, y;
int grid[H][W];
bool vis[H][W];

signed main() {
    close;
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

    // Initialize the priority queue with border cells
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    memset(vis, false, sizeof(vis));

    // Add boundary cells to the priority queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                vis[i][j] = true;
                pq.push({grid[i][j], {i, j}});
            }
        }
    }

    int remaining = h * w;
    vector<int> ans(y + 2, remaining); // Default answer is full area

    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();

        int x = pos.fi, y = pos.se;
        int current_year = height;

        if (current_year > Y) {
            break;
        }

        remaining--;
        ans[current_year] = min(ans[current_year], remaining);

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({grid[nx][ny], {nx, ny}});
            }
        }
    }

    // Propagate answers in case some years are skipped due to no changes
    for (int i = 1; i <= Y; ++i) {
        ans[i] = min(ans[i], ans[i - 1]);
    }

    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}