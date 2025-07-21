#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<vector<bool>> can_capture(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> has_piece(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        has_piece[a][b] = true;
    }

    // Check the range of cells that can capture a piece based on the given pieces
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!has_piece[i][j]) { // Only consider empty cells
                int capture_count = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + 2 * (k % 2), nj = j + 2 * (k / 2);
                    if (n > ni && ni > 0 && nj > 0 && nj <= n && has_piece[ni][nj]) {
                        capture_count++;
                    }
                }
                can_capture[i][j] = capture_count > 0;
            }
        }
    }

    long long count = 0;
    // Count cells that can't be occupied by any existing piece
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!has_piece[i][j] && !can_capture[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}