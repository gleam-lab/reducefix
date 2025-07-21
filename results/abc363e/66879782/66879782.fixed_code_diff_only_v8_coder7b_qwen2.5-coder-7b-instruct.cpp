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
    queue<pair<int, pair<int, int>>> q;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                q.push({height[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [H, p] = q.front();
        auto [r, c] = p;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc] || height[nr][nc] > H) continue;

            visited[nr][nc] = true;
            q.push({H, {nr, nc}});
        }
    }

    vector<int> areas(y + 1, 0);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j]) {
                int curr_h = height[i][j];
                q.push({curr_h, {i, j}});
                visited[i][j] = true;
                int area = 1;

                while (!q.empty()) {
                    auto [H, p] = q.front();
                    auto [r, c] = p;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nr = r + di[k][0];
                        int nc = c + di[k][1];

                        if (nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc] || height[nr][nc] > H) continue;

                        visited[nr][nc] = true;
                        q.push({H, {nr, nc}});
                        area++;
                    }
                }

                areas[curr_h]++;
                areas[y] -= area;
            }
        }
    }

    partial_sum(areas.begin(), areas.end(), areas.begin());

    for (int i = 1; i <= y; i++) {
        cout << areas[i] << '\n';
    }

    return 0;
}