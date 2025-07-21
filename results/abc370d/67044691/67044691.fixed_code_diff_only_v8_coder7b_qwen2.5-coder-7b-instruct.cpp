#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Query {
    int type, r, c;
};

vector<vector<int>> grid;

void init(int h, int w) {
    grid.resize(h, vector<int>(w, 1));
}

void processQuery(const Query &query) {
    int r = query.r - 1, c = query.c - 1;
    if (grid[r][c] == 0) return;
    grid[r][c] = 0;
    // Check up
    for (int i = r - 1; i >= 0; --i) {
        if (grid[i][c] == 1) {
            grid[i][c] = 0;
        } else break;
    }
    // Check down
    for (int i = r + 1; i < grid.size(); ++i) {
        if (grid[i][c] == 1) {
            grid[i][c] = 0;
        } else break;
    }
    // Check left
    for (int j = c - 1; j >= 0; --j) {
        if (grid[r][j] == 1) {
            grid[r][j] = 0;
        } else break;
    }
    // Check right
    for (int j = c + 1; j < grid[0].size(); ++j) {
        if (grid[r][j] == 1) {
            grid[r][j] = 0;
        } else break;
    }
}

int countWalls() {
    int count = 0;
    for (auto &row : grid) {
        for (int cell : row) {
            count += cell;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    init(h, w);

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type >> queries[i].r >> queries[i].c;
        if (queries[i].type == 1) {
            processQuery(queries[i]);
        }
    }

    cout << countWalls() << '\n';

    return 0;
}