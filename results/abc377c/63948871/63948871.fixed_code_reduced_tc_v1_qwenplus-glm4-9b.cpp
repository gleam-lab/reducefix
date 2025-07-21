#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = true; // Mark the piece's position

        // Check all capture positions
        if (x + 2 <= N && y + 1 <= N) grid[x + 2][y + 1] = true;
        if (x + 1 <= N && y + 2 <= N) grid[x + 1][y + 2] = true;
        if (x - 1 >= 1 && y + 2 <= N) grid[x - 1][y + 2] = true;
        if (x - 2 >= 1 && y + 1 <= N) grid[x - 2][y + 1] = true;
        if (x - 2 >= 1 && y - 1 >= 1) grid[x - 2][y - 1] = true;
        if (x - 1 >= 1 && y - 2 >= 1) grid[x - 1][y - 2] = true;
        if (x + 1 <= N && y - 2 >= 1) grid[x + 1][y - 2] = true;
        if (x + 2 <= N && y - 1 >= 1) grid[x + 2][y - 1] = true;
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!grid[i][j]) ans++; // Count unmarked (empty) squares
        }
    }

    cout << ans << endl;
    return 0;
}