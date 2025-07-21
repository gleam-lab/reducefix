#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    int height[h][w];
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    int di[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

    // Read heights and initialize border cells
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
            }
        }
    }

    // Process all cells
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sink[i][j] == INT_MAX) {
                for (auto d : di) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= h || nj < 0 || nj >= w || height[ni][nj] > height[i][j]) continue;
                    sink[i][j] = min(sink[i][j], sink[ni][nj]);
                }
            }
        }
    }

    // Calculate the remaining area for each year
    vector<int> remaining(h * w), prefix_sum(h * w + 1, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sink[i][j] > y) {
                remaining[i * w + j] = 1;
            }
        }
    }
    for (int i = 0; i < h * w; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + remaining[i];
    }

    // Output the results
    for (int i = 1; i <= y; i++) {
        cout << h * w - prefix_sum[i + 1] << '\n';
    }
}