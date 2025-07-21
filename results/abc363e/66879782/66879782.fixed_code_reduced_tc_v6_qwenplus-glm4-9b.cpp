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
    vector<vector<int>> sink(h, vector<int>(w, 0));
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    // Initialize the sinking process
    queue<pair<int, pair<int, int>>> q; // queue to store sections to be processed
    vector<vector<bool>> visited(h, vector<bool>(w, false)); // visited sections

    // Add borders to the queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                visited[i][j] = true;
                q.push({height[i][j], {i, j}});
            }
        }
    }

    // Perform the sinking simulation
    while (!q.empty()) {
        auto [H, p] = q.front();
        q.pop();
        auto [r, c] = p;
        for (int i = 0; i < 4; ++i) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc]) {
                visited[nr][nc] = true;
                if (height[nr][nc] <= H) {
                    sink[nr][nc] = H;
                    q.push({height[nr][nc], {nr, nc]]);
                }
            }
        }
    }

    // Calculate the remaining area above sea level each year
    for (int year = 1; year <= y; ++year) {
        int remaining_area = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (sink[i][j] > year) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << '\n';
    }
}