#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const int INF = 1e9;

struct Point {
    int x, y, height;
    bool operator<(const Point &other) const {
        return height > other.height;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    priority_queue<Point> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the priority queue with all boundary cells
    for (int i = 0; i < h; ++i) {
        pq.emplace(grid[i][0], i, 0);
        pq.emplace(grid[i][w - 1], i, w - 1);
        visited[i][0] = true;
        visited[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        pq.emplace(grid[0][j], 0, j);
        pq.emplace(grid[h - 1][j], h - 1, j);
        visited[0][j] = true;
        visited[h - 1][j] = true;
    }

    vector<int> result(y + 1, h * w);
    int current_level = 0;

    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        if (height <= current_level) continue;
        current_level = height;
        --result[current_level];

        static constexpr array<pair<int, int>, 4> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto &[dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(grid[nx][ny], nx, ny);
            }
        }
    }

    for (int i = 1; i <= y; ++i) {
        result[y - i + 1] += result[y - i];
        cout << result[y - i + 1] << '\n';
    }

    return 0;
}