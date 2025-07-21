#include <iostream>
#include <vector>
using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> can_place(n, vector<bool>(n, true));

    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        x--; y--; // Convert to zero-indexed

        // Mark all squares that this piece can capture
        for (int j = 0; j < 8; ++j) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                can_place[nx][ny] = false;
            }
        }
    }

    // Count the number of squares that can be placed on
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (can_place[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}