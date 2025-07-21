#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

struct Node {
    int x, y, val;
    bool operator <(const Node &a) const {
        return val < a.val; // Fix the comparison operator here
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    // We don't need to use a vis array or a priority queue in this case
    int total_area = h * w; // Count all cells initially
    for (int year = 1; year <= y; year++) {
        int new_sunk_area = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] <= year) { // If the elevation is less than or equal to the year (sea level)
                    new_sunk_area++; // This cell will sink
                    // Check adjacent cells
                    if (i > 0 && grid[i - 1][j] <= year) new_sunk_area++;
                    if (i < h - 1 && grid[i + 1][j] <= year) new_sunk_area++;
                    if (j > 0 && grid[i][j - 1] <= year) new_sunk_area++;
                    if (j < w - 1 && grid[i][j + 1] <= year) new_sunk_area++;
                }
            }
        }
        total_area -= new_sunk_area; // Subtract the newly sunk area
        cout << total_area << endl;
    }

    return 0;
}