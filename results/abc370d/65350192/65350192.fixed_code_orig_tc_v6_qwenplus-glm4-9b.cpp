#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> wall_rows(W), wall_cols(H);

    // Initialize with walls
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            wall_rows[j].insert(i);
            wall_cols[i].insert(j);
        }
    }

    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-based index

        // Find and remove the wall if it exists
        if (wall_rows[C].find(R) != wall_rows[C].end()) {
            wall_rows[C].erase(R);
            wall_cols[R].erase(C);
        } else {
            // Find nearest wall in the row set
            auto row_iter_up = wall_rows[C].lower_bound(R);
            auto row_iter_down = wall_rows[C].upper_bound(R);

            // Find nearest wall in the column set
            auto col_iter_left = wall_cols[R].lower_bound(C);
            auto col_iter_right = wall_cols[R].upper_bound(C);

            // Find the closest walls to remove
            int closest_row = INT_MAX;
            int closest_col = INT_MAX;

            if (row_iter_up != wall_rows[C].end()) closest_row = *row_iter_up;
            if (row_iter_down != wall_rows[C].begin()) {
                closest_row = *(prev(row_iter_down));
            }

            if (col_iter_left != wall_cols[R].end()) closest_col = *col_iter_left;
            if (col_iter_right != wall_cols[R].begin()) {
                closest_col = *(prev(col_iter_right));
            }

            // Remove the closest walls
            if (closest_row != INT_MAX) {
                wall_rows[C].erase(closest_row);
                wall_cols[closest_row].erase(C);
            }
            if (closest_col != INT_MAX) {
                wall_cols[R].erase(closest_col);
                wall_rows[closest_col].erase(R);
            }
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < W; i++) {
        remaining_walls += wall_rows[i].size();
    }
    for (int i = 0; i < H; i++) {
        remaining_walls += wall_cols[i].size();
    }

    // Output the result
    cout << remaining_walls << endl;
    return 0;
}