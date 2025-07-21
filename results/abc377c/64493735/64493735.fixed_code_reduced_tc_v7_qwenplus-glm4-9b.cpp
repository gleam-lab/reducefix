#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N + 1, vector<bool>(N + 1, true)); // Using (N+1)x(N+1) to avoid boundary issues

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // Mark the capturing area for the piece at (a, b)
        for (int di = -2; di <= 2; di++) {
            for (int dj = -2; dj <= 2; dj++) {
                int ni = a + di, nj = b + dj;
                if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                    grid[ni][nj] = false; // Mark this cell as captured by this piece
                }
            }
        }
    }

    // Count the number of empty cells not captured by any piece
    long long empty_cells = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j]) {
                empty_cells++;
            }
        }
    }

    cout << empty_cells << endl;

    return 0;
}