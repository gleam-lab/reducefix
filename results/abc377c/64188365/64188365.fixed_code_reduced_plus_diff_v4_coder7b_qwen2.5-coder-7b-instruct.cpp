#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    set<pair<long long, long long>> unsafe_squares;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        board[a][b] = true;

        // Mark unsafe squares for capturing
        for (long long dx = -2; dx <= 2; ++dx) {
            for (long long dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) == 3 && dx != 0 && dy != 0) {
                    long long nx = a + dx, ny = b + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        unsafe_squares.insert({nx, ny});
                    }
                }
            }
        }
    }

    // Count safe squares
    long long safe_count = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!board[i][j] && unsafe_squares.find({i, j}) == unsafe_squares.end()) {
                ++safe_count;
            }
        }
    }

    cout << safe_count << endl;
    return 0;
}