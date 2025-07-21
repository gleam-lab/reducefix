#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000000000;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> grid(N + 1, vector<bool>(N + 1, true)); // grid[i][j] = true if empty, false if occupied

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        grid[a][b] = false; // Mark the piece as occupied

        // Mark all positions this piece can capture
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = a + dx;
                int ny = b + dy;
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    grid[nx][ny] = false; // Mark this position as captured
                }
            }
        }
    }

    // Count the number of empty squares
    long long emptyCount = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (grid[i][j]) {
                emptyCount++;
            }
        }
    }

    cout << emptyCount << endl;
}

int main() {
    solve();
    return 0;
}