#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1010;

int h, w, y;
int a[MAXN][MAXN];
bool used[MAXN][MAXN];

struct Node {
    int height, x, y;
    Node(int h, int x, int y) : height(h), x(x), y(y) {}
    bool operator<(const Node& other) const {
        return height > other.height;
    }
};

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!used[i][j] && a[i][j] > sea_level) {
                q.emplace(i, j);
                used[i][j] = true;
            }
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !used[nx][ny] && a[nx][ny] > sea_level) {
                q.emplace(nx, ny);
                used[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> y;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    priority_queue<Node> pq;
    for (int i = 0; i < h; ++i) {
        pq.emplace(a[i][0], i, 0);
        pq.emplace(a[i][w - 1], i, w - 1);
    }
    for (int j = 1; j < w - 1; ++j) {
        pq.emplace(a[0][j], 0, j);
        pq.emplace(a[h - 1][j], h - 1, j);
    }

    int ans = h * w;
    while (!pq.empty() && pq.top().height <= y) {
        auto [sea_level, _, _] = pq.top();
        pq.pop();
        --ans;
        bfs(sea_level);
    }

    cout << ans << endl;

    return 0;
}