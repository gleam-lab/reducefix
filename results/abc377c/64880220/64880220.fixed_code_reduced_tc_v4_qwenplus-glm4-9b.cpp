#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<vector<bool>> can_capture(n + 1, vector<bool>(n + 1, false));

    // Mark squares that can be captured by each piece
    for (auto p : pieces) {
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                if (i == 0 || j == 0) { // Skip the center square
                    continue;
                }
                int x = p.first + i;
                int y = p.second + j;
                if (x >= 1 && x <= n && y >= 1 && y <= n) {
                    can_capture[x][y] = true;
                }
            }
        }
    }

    // Count the number of squares that can be occupied
    long long valid_squares = n * n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!can_capture[i][j]) {
                valid_squares--;
            }
        }
    }

    cout << valid_squares << endl;
    return 0;
}