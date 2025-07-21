#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> areas(y + 1);

    for (int t = 1; t <= y; t++) {
        int count = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + di[i][0];
                int nc = c + di[i][1];
                if (nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc] || height[nr][nc] > t) continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && height[i][j] <= t) {
                    count++;
                }
            }
        }
        areas[t] = count;
    }

    for (int i = 1; i <= y; i++) {
        areas[i] += areas[i - 1];
        cout << h * w - areas[i] << '\n';
    }

    return 0;
}