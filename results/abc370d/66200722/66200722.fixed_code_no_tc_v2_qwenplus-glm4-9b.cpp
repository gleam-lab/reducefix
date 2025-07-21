#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int size) : parent(size, -1) {}

    int find(int x) {
        if (parent[x] < 0) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSets(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    map<int, int> colIndex;
    int idx = 0;
    // Initialize union-find structures for columns and rows
    UnionFind ufCol(w);
    UnionFind ufRow(h);

    vector<vector<int>> wallCount(h, vector<int>(w));
    vector<vector<bool>> hasBomb(h, vector<bool>(w, false));

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-indexed

        if (hasBomb[r][c]) continue; // Skip if bomb already placed here

        hasBomb[r][c] = true; // Place bomb

        // Find all walls that need to be destroyed
        vector<pair<int, int>> affectedColumns, affectedRows;

        // Check above
        for (int j = c - 1; j >= 0; --j) {
            if (wallCount[r][j] > 0) {
                affectedColumns.push_back({r, j});
                break;
            }
        }

        // Check below
        for (int j = c + 1; j < w; ++j) {
            if (wallCount[r][j] > 0) {
                affectedColumns.push_back({r, j});
                break;
            }
        }

        // Check left
        for (int i = r - 1; i >= 0; --i) {
            if (wallCount[i][c] > 0) {
                affectedRows.push_back({i, c});
                break;
            }
        }

        // Check right
        for (int i = r + 1; i < h; ++i) {
            if (wallCount[i][c] > 0) {
                affectedRows.push_back({i, c});
                break;
            }
        }

        // Remove walls and merge sets in union-find
        for (auto [i, j] : affectedColumns) {
            if (hasBomb[i][j]) continue;
            hasBomb[i][j] = true;
            wallCount[i][j]--;

            int colId = colIndex[j];
            if (colId == 0) {
                colId = idx++;
                colIndex[j] = colId;
            }

            ufCol.unionSets(colId, colIndex[j]);
        }

        for (auto [i, j] : affectedRows) {
            if (hasBomb[i][j]) continue;
            hasBomb[i][j] = true;
            wallCount[i][j]--;

            int rowId = colIndex[j];
            if (rowId == 0) {
                rowId = idx++;
                colIndex[j] = rowId;
            }

            ufRow.unionSets(rowId, colIndex[j]);
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (wallCount[i][j] > 0) {
                remainingWalls += wallCount[i][j];
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}