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

    // Read input heights
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> height[i][j];

    // Initialize sink levels and priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    // Process the priority queue to update sink levels
    while (!pq.empty()) {
        auto [H, p] = pq.top();
        auto [r, c] = p;
        pq.pop();

        if (visited[r][c])
            continue;

        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;
            if (height[nr][nc] <= H && sink[nr][nc] > H) {
                sink[nr][nc] = H;
                pq.push({H, {nr, nc}});
            }
        }
    }

    // Calculate areas above sea level for each year
    vector<int> areas(y + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink[i][j] <= y)
                areas[sink[i][j]]++;
        }
    }

    // Compute prefix sums to get cumulative areas
    partial_sum(areas.begin(), areas.end(), areas.begin());

    // Print results for each year
    for (int i = 1; i <= y; ++i)
        cout << h * w - areas[i] << '\n';

    return 0;
}