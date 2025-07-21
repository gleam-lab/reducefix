#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, m;
vector<pair<int, int>> pieces;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<vector<bool>> can_capture;

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
    }

    // Initialize the can_capture grid
    can_capture.assign(n + 1, vector<bool>(n + 1, false));
    for (auto& piece : pieces) {
        int x = piece.first;
        int y = piece.second;
        can_capture[x][y] = true;

        // Check all 4 directions
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                can_capture[nx][ny] = true;
                nx += dx[i];
                ny += dy[i];
            }
        }
    }

    // Calculate the number of safe squares
    long long safe_squares = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!can_capture[i][j]) {
                safe_squares++;
            }
        }
    }

    cout << safe_squares << endl;
    return 0;
}