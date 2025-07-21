#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
    int x, y, height;
};

struct Comparator {
    bool operator()(const Cell& a, const Cell& b) const {
        return a.height < b.height;
    }
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    priority_queue<Cell, vector<Cell>, Comparator> pq;
    set<pair<int, int>> alive;

    // Read the grid and initialize the priority queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({i, j, grid[i][j]});
            }
            alive.insert({i, j});
        }
    }

    // Function to propagate the sinking
    auto propagate = [&](int x, int y) {
        if (x < 0 || x >= h || y < 0 || y >= w || grid[x][y] <= y) return;
        grid[x][y] = y;
        if (alive.count({x, y})) {
            alive.erase({x, y});
        }
        pq.push({x, y, grid[x][y]});
    };

    // Process each year
    for (int year = 0; year < y; ++year) {
        while (!pq.empty()) {
            Cell c = pq.top(); pq.pop();
            propagate(c.x, c.y);
        }

        // Calculate the remaining area
        int remaining_area = 0;
        for (const auto& p : alive) {
            remaining_area += grid[p.first][p.second] - year;
        }
        cout << remaining_area << '\n';
    }

    return 0;
}