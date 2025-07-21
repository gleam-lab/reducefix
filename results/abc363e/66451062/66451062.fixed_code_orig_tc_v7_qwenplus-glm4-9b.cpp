#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<int>> area(H, vector<int>(W, 1)); // Initialize area to 1 since all cells are initially above the sea level

    // Calculate initial area of the island
    int total_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            total_area += area[i][j];
        }
    }

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        // Update the area of cells that have sunk
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= year) {
                    visited[i][j] = true;
                } else {
                    // Check all four neighbors
                    if (i > 0 && !visited[i - 1][j] && A[i - 1][j] > year) {
                        visited[i - 1][j] = true;
                        area[i - 1][j] = 0;
                    }
                    if (i < H - 1 && !visited[i + 1][j] && A[i + 1][j] > year) {
                        visited[i + 1][j] = true;
                        area[i + 1][j] = 0;
                    }
                    if (j > 0 && !visited[i][j - 1] && A[i][j - 1] > year) {
                        visited[i][j - 1] = true;
                        area[i][j - 1] = 0;
                    }
                    if (j < W - 1 && !visited[i][j + 1] && A[i][j + 1] > year) {
                        visited[i][j + 1] = true;
                        area[i][j + 1] = 0;
                    }
                }
            }
        }

        // Calculate the new area above the sea level
        int new_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    new_area += area[i][j];
                }
            }
        }

        // Output the new area
        cout << new_area << endl;
    }

    return 0;
}