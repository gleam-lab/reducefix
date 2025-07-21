#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool inBounds(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        pieces[i].first--; // Convert to 0-indexed
        pieces[i].second--;
    }

    // Create a set to store all the attacked positions
    unordered_map<int, unordered_map<int, bool>> attacked;

    for (const auto &p : pieces) {
        for (int i = 0; i < 8; ++i) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (inBounds(x, y, n)) {
                attacked[x][y] = true;
            }
        }
    }

    int freeSpaces = n * n;
    int attackedSpaces = 0;
    for (const auto &row : attacked) {
        for (const auto &cell : row.second) {
            if (cell.second) {
                attackedSpaces++;
            }
        }
    }

    cout << freeSpaces - attackedSpaces << endl;
    return 0;
}