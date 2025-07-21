#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)n; ++i)

using ll = long long;
using vi = vector<int>;

const int MAX_H = 400001;
const int MAX_W = 400001;

int h, w, q;
vector<vector<set<int>>> row(MAX_H + 1, vector<set<int>>(MAX_W + 1));
vector<vector<set<int>>> col(MAX_H + 1, vector<set<int>>(MAX_W + 1));
vector<vector<bool>> grid(MAX_H + 2, vector<bool>(MAX_W + 2, true));

void removeWall(int x, int y) {
    grid[x][y] = false;
    // Remove wall in row
    for (int i = 1; i <= h; ++i) {
        if (row[i][y].count(i)) {
            row[i][y].erase(i);
            break;
        }
    }
    // Remove wall in column
    for (int j = 1; j <= w; ++j) {
        if (col[j][x].count(j)) {
            col[j][x].erase(j);
            break;
        }
    }
}

void processQueries() {
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            // If a bomb is placed at a location without a wall, remove walls in all 4 directions
            if (!grid[i][j]) {
                // Up
                for (int k = i - 1; k >= 1; --k) {
                    if (grid[k][j]) break;
                    row[k][j].erase(k + 1);
                }
                // Down
                for (int k = i + 1; k <= h; ++k) {
                    if (grid[k][j]) break;
                    row[k][j].erase(k - 1);
                }
                // Left
                for (int k = j - 1; k >= 1; --k) {
                    if (grid[i][k]) break;
                    col[k][i].erase(k + 1);
                }
                // Right
                for (int k = j + 1; k <= w; ++k) {
                    if (grid[i][k]) break;
                    col[k][i].erase(k - 1);
                }
            }
        }
    }
}

int main() {
    cin >> h >> w >> q;
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (!grid[x][y]) {
            removeWall(x, y);
        }
        grid[x][y] = false;
    }

    processQueries();
    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}