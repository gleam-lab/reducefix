#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9;

bool row[MAX_N + 1], col[MAX_N + 1];
bool up[2][MAX_N + 1], down[2][MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y; // Convert to 0-based index
        row[y] = true;
        col[x] = true;
        up[(x + y) & 1][y - x + n] = true;
        down[(x + y) & 1][x + y] = true;
    }

    int total_squares = n * n;
    int occupied_squares = m + accumulate(row, row + n, 0) + accumulate(col, col + n, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!row[j] && !col[i] && !up[(i + j) & 1][j - i + n] && !down[(i + j) & 1][i + j]) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << '\n';
    }

    return 0;
}