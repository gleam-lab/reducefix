#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_N 1000000000

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N + 1, vector<bool>(N + 1, true)); // Using 1-based indexing

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        // Mark the occupied cells and the cells that can be attacked
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    grid[nx][ny] = false;
                }
            }
        }
    }

    // Count the number of empty cells
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}