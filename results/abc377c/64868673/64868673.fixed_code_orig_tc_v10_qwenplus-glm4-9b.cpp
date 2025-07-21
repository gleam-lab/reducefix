#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<vector<bool>> captured(n + 1, vector<bool>(n + 1, false));
    vector<pair<int, int>> pieces(m);

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Process each piece and mark captured squares
    for (const auto& p : pieces) {
        queue<pair<int, int>> q;
        q.push({p.first, p.second});
        captured[p.first][p.second] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx > 0 && nx <= n && ny > 0 && ny <= n && !captured[nx][ny]) {
                    captured[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Count the number of unoccupied squares
    long long free_squares = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!captured[i][j]) {
                free_squares++;
            }
        }
    }

    cout << free_squares << endl;

    return 0;
}