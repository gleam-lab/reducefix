#include <iostream>
#include <vector>
using namespace std;

const vector<pair<int, int>> moves = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isWithinBounds(int x, int y, int n) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> captured(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int nx, ny;

        // Mark the piece and its capturing area
        captured[x][y] = true;
        for (auto& move : moves) {
            nx = x + move.first;
            ny = y + move.second;
            if (isWithinBounds(nx, ny, n)) {
                captured[nx][ny] = true;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!captured[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}