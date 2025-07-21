#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<Point> pieces(m);
    vector<vector<bool>> can_capture(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1};
        // Set the ranges of cells that can be captured by the piece at (a, b)
        can_capture[a - 1 + 2][b - 1 + 1] = true;
        can_capture[a - 1 + 1][b - 1 + 2] = true;
        can_capture[a - 1 - 1 + 2][b - 1] = true;
        can_capture[a - 1 - 2][b - 1 + 1] = true;
        can_capture[a - 1 - 2][b - 1 - 1] = true;
        can_capture[a - 1 - 1][b - 1 - 2] = true;
        can_capture[a - 1 + 1][b - 1 - 2] = true;
        can_capture[a - 1 + 2][b - 1 - 1] = true;
    }

    // Calculate the number of cells that can be placed safely
    int safe_cells = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool is_safe = true;
            for (int x = 0; x < m; ++x) {
                int dx = abs(i - pieces[x].x);
                int dy = abs(j - pieces[x].y);
                // Check all possible capture ranges for the piece
                if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
                    is_safe = false;
                    break;
                }
            }
            if (is_safe) {
                ++safe_cells;
            }
        }
    }

    cout << safe_cells << endl;
    return 0;
}