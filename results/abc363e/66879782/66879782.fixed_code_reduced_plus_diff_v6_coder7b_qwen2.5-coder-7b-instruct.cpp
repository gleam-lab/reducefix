#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));

    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                visited[i][j] = true;
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (visited[i][j]) {
                q.push({height[i][j], {i, j}});
            }
        }
    }

    while (!q.empty()) {
        auto [H, p] = q.front();
        auto [r, c] = p;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (visited[nr][nc]) continue;
            if (height[nr][nc] <= H) {
                sink[nr][nc] = min(H, sink[nr][nc]);
                visited[nr][nc] = true;
                q.push({H, {nr, nc}});
            }
        }
    }

    vector<int> pref(y + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink[i][j] > y) {
                pref[y]++;
                break;
            } else {
                pref[sink[i][j]]++;
            }
        }
    }

    for (int i = y - 1; i >= 0; --i) {
        pref[i] += pref[i + 1];
    }

    for (int i = 0; i <= y; ++i) {
        cout << h * w - pref[i] << '\n';
    }

    return 0;
}