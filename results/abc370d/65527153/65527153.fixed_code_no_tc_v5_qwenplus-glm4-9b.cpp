#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e5 + 5;
ll grid[N][N];
ll remainingWalls = 0;

void solve() {
    ll H, W, Q;
    cin >> H >> W >> Q;
    fill(grid[1].begin(), grid[1].end(), H);  // Initialize columns with number of rows
    fill(grid[1].begin() + W + 1, grid[1].end() + 2 * W + 1, -1);  // Initialize rows with -1
    fill(grid[1 + W].begin(), grid[1 + W].end(), W);  // Initialize columns with number of rows
    fill(grid[1 + W].begin() + H + 1, grid[1 + W].end() + 2 * H + 1, -1);  // Initialize rows with -1

    remainingWalls = H * W;  // Initially, all walls are present

    while (Q--) {
        ll r, c;
        cin >> r >> c;
        r++; c++;  // Convert to 1-based index

        // Check if the wall at (r, c) exists
        if (grid[r][c] != 0) {
            grid[r][c]--;  // Destroy the wall
            remainingWalls--;
        } else if (grid[r][c] == 0) {  // If no wall at (r, c), destroy walls upwards and downwards
            ll count = 0, i = r;
            while (i > 1 && grid[i - 1][c] == 0) {
                grid[i - 1][c]--;  // Destroy the wall
                remainingWalls--;
                count++;
                if (grid[i - 1][c] == 0) {
                    i--;
                } else {
                    break;
                }
            }
            i = r;
            while (i < H && grid[i + 1][c] == 0) {
                grid[i + 1][c]--;  // Destroy the wall
                remainingWalls--;
                count++;
                if (grid[i + 1][c] == 0) {
                    i++;
                } else {
                    break;
                }
            }
        } else if (grid[r][c] == -1) {  // If no wall at (r, c), destroy walls left and right
            ll count = 0, j = c;
            while (j > 1 && grid[r][j - 1] == 0) {
                grid[r][j - 1]--;  // Destroy the wall
                remainingWalls--;
                count++;
                if (grid[r][j - 1] == 0) {
                    j--;
                } else {
                    break;
                }
            }
            j = c;
            while (j < W && grid[r][j + 1] == 0) {
                grid[r][j + 1]--;  // Destroy the wall
                remainingWalls--;
                count++;
                if (grid[r][j + 1] == 0) {
                    j++;
                } else {
                    break;
                }
            }
        }
    }

    cout << remainingWalls << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}