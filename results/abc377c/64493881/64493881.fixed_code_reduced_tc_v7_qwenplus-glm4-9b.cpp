#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> captured(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        // Check in all 8 directions
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = a + dx;
                int ny = b + dy;

                // Check if the new cell is within the grid boundaries and not already captured
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N && !captured[nx][ny]) {
                    captured[nx][ny] = true;
                }
            }
        }
    }

    // Count all free cells
    long long free_cells = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!captured[i][j]) {
                free_cells++;
            }
        }
    }

    cout << free_cells << endl;

    return 0;
}