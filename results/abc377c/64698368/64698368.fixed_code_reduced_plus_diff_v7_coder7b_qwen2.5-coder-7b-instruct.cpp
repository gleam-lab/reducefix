#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_N = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // Directions for capturing pieces
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    vector<vector<bool>> board(N, vector<bool>(N));
    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        --x, --y; // Convert to zero-based index
        board[x][y] = true;
    }

    vector<long long> dp(1LL << 8, 0);
    dp[0] = 1;

    for (int dir = 0; dir < 8; ++dir) {
        vector<long long> ndp(1LL << 8, 0);
        for (int state = 0; state < (1LL << 8); ++state) {
            if (dp[state] == 0) continue;
            bool valid = true;
            for (int d = 0; d < 8; ++d) {
                int next_state = state;
                for (int step = 1; ; ++step) {
                    int nx = step * directions[d].first + directions[dir].first;
                    int ny = step * directions[d].second + directions[dir].second;
                    if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) break;
                    next_state |= (1LL << (nx * 8 + ny));
                    if (next_state != state) break;
                }
                if ((next_state & state) != 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ndp[state] += dp[state];
            }
        }
        swap(dp, ndp);
    }

    long long total_safe_positions = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!board[i][j]) {
                total_safe_positions += dp[0];
            } else {
                for (int dir = 0; dir < 8; ++dir) {
                    int nx = i + directions[dir].first;
                    int ny = j + directions[dir].second;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N || !board[nx][ny]) {
                        total_safe_positions += dp[(1LL << (nx * 8 + ny))];
                    }
                }
            }
        }
    }

    cout << total_safe_positions << endl;
    return 0;
}