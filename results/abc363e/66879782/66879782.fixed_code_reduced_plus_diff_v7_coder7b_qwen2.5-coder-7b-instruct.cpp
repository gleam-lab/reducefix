#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

struct Point {
    int x, y, h;
    bool operator<(const Point& other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> heights(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<int>> sea_level(h, vector<int>(w, INT_MAX));

    priority_queue<Point> pq;

    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> heights[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sea_level[i][j] = heights[i][j];
                pq.push({heights[i][j], {i, j}});
            } else {
                sea_level[i][j] = INT_MAX;
            }
        }
    }

    while (!pq.empty()) {
        auto [H, p] = pq.top(); pq.pop();
        auto [r, c] = p;
        if (visited[r][c]) continue;
        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + di[i][0], nc = c + di[i][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (heights[nr][nc] <= H && sea_level[nr][nc] > H) {
                sea_level[nr][nc] = H;
                pq.push({H, {nr, nc}});
            }
        }
    }

    vector<int> pref(y + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sea_level[i][j] <= y) {
                pref[sea_level[i][j]]++;
            }
        }
    }
    for (int i = 1; i <= y; ++i) {
        pref[i] += pref[i - 1];
        cout << h * w - pref[i] << '\n';
    }

    return 0;
}