#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // The initial island area
    int initial_area = H * W;

    // Process for Y years
    for (int year = 1; year <= Y; year++) {
        // Count the number of sections that sink this year
        int sink_count = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int adj_to_sea = 0;
                // Check adjacent cells
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue; // Skip itself
                        int nx = i + dx;
                        int ny = j + dy;
                        // Check if the adjacent cell is at sea level or below
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W && (A[nx][ny] == year || A[nx][ny] < year)) {
                            adj_to_sea++;
                        }
                    }
                }
                // If all adjacent cells are at sea level or below, this cell sinks
                if (adj_to_sea == 4) {
                    sink_count++;
                    A[i][j] = year; // Mark as sea level
                }
            }
        }
        // Subtract the number of cells sinking from the initial island area
        initial_area -= sink_count;
        // Output the remaining area
        cout << initial_area << endl;
    }

    return 0;
}