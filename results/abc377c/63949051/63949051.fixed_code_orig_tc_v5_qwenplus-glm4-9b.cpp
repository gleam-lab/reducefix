#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N+1, vector<int>(N+1, 0));

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        grid[y][x] = 1;

        // Mark the squares that can be captured by the current piece
        grid[y-2][x+1] = 1;
        grid[y+2][x+1] = 1;
        grid[y+1][x+2] = 1;
        grid[y-1][x+2] = 1;
        grid[y-2][x-1] = 1;
        grid[y+2][x-1] = 1;
        grid[y+1][x-2] = 1;
        grid[y-1][x-2] = 1;
    }

    int emptyCount = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (grid[i][j] == 0) {
                emptyCount++;
            }
        }
    }

    cout << emptyCount << endl;

    return 0;
}