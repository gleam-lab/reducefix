#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> sink(h, vector<bool>(w, false));
    queue<pair<int, int>> q;

    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = true;
                q.emplace(i, j);
            }
        }
    }

    vector<int> result(y + 1, 0);
    result[0] = h * w;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nr = r + di[k][0];
            int nc = c + di[k][1];

            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !sink[nr][nc] && height[nr][nc] <= height[r][c]) {
                sink[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }
    }

    for (int t = 1; t <= y; ++t) {
        result[t] = result[t - 1];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (height[i][j] > t && !sink[i][j]) {
                    result[t]--;
                }
            }
        }
    }

    for (int i = 1; i <= y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}