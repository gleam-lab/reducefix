#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the maximum size for rows, columns, and diagonals
const int MAX_N = 1000000000;

// Define arrays to store captured rows, columns, diagonals
bool captured_rows[MAX_N + 1];
bool captured_columns[MAX_N + 1];
bool captured_diagonals_up[MAX_N * 2 + 1];
bool captured_diagonals_down[MAX_N * 2 + 1];

// Function to check if a square is captured by existing pieces
bool is_captured(int row, int col) {
    if (captured_rows[row] || captured_columns[col]) return true;
    int diag1 = row + col;
    int diag2 = row - col;
    if (captured_diagonals_up[diag1] || captured_diagonals_down[diag2]) return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // Convert to 0-based indexing

        // Mark the corresponding row, column, and diagonals as captured
        captured_rows[a] = true;
        captured_columns[b] = true;
        captured_diagonals_up[a + b] = true;
        captured_diagonals_down[a - b] = true;
    }

    // Count the number of valid squares
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!is_captured(i, j)) {
                count++;
            }
        }
    }

    // Output the result
    cout << count << endl;
    return 0;
}