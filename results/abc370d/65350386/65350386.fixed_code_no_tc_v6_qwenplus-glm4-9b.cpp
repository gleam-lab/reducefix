#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> walls(h, vector<int>(w, h * w)); // Create a 2D vector to represent walls with a count of each wall
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> walls[i][j];
            walls[i][j]--;
        }
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        queries[i] = {r - 1, c - 1}; // Store queries with 1-based index
    }

    // Sort queries by row and column for efficient processing
    sort(queries.begin(), queries.end());

    int remainingWalls = 0;
    int currentRow = -1;
    for (const auto& query : queries) {
        if (currentRow != query.first) {
            // Traverse the entire row to count remaining walls
            for (int col = 0; col < w; ++col) {
                remainingWalls += walls[query.first][col];
            }
            currentRow = query.first;
        }
        // Check if the wall at the query position is still present
        remainingWalls -= walls[query.first][query.second];
    }

    cout << remainingWalls << endl;
    return 0;
}