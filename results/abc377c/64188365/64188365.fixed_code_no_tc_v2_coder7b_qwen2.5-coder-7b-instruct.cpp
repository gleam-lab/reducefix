#include <bits/stdc++.h>
using namespace std;

bool isValid(long long x, long long y, long long n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<pair<long long, long long>> captures(8);

    // Define all possible capture moves
    captures[0] = {2, 1};
    captures[1] = {1, 2};
    captures[2] = {-1, 2};
    captures[3] = {-2, 1};
    captures[4] = {-2, -1};
    captures[5] = {-1, -2};
    captures[6] = {1, -2};
    captures[7] = {2, -1};

    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a; --b; // Convert to zero-based index
        board[a][b] = true;

        // Check all possible capture moves
        for (auto& move : captures) {
            long long nx = a + move.first;
            long long ny = b + move.second;
            if (isValid(nx, ny, n)) {
                board[nx][ny] = false; // Mark as invalid if it can be captured
            }
        }
    }

    // Count the number of valid positions
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!board[i][j]) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}