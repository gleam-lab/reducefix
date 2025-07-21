#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> row(h + 1, vector<int>(w + 1, 0));
    vector<vector<int>> col(h + 1, vector<int>(w + 1, 0));

    int r, c;
    while (q--) {
        cin >> r >> c;
        r--;
        c--;

        // Check if the wall exists at (r, c)
        if (row[r][c] == 1) {
            row[r][c] = 0;
            col[c][r] = 0; // Destroy the wall in the column as well
        } else {
            // Mark all walls to be destroyed in the row and column
            for (int i = 0; i <= h; i++) {
                if (row[i][c] == 1) {
                    row[i][c] = -1; // Mark as destroyed
                }
            }
            for (int i = 0; i <= w; i++) {
                if (col[i][r] == 1) {
                    col[i][r] = -1; // Mark as destroyed
                }
            }
        }
    }

    // Calculate the number of remaining walls
    int ans = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            ans += row[i][j] == 0;
        }
    }
    cout << ans << endl;

    return 0;
}