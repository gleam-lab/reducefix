#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    Node(int x, int y) : x(x), y(y) {}
};

vector<vector<pair<Node, bool>>> grid;
vector<vector<bool>> visited;

void destroyWalls(int x, int y) {
    queue<Node> q;
    q.push({x, y});
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        if (visited[cx][cy]) continue;
        visited[cx][cy] = true;
        
        if (cx > 0 && !grid[cx-1][cy].second) {
            q.push({cx-1, cy});
            grid[cx-1][cy].second = false;
        }
        if (cx < grid.size() - 1 && !grid[cx+1][cy].second) {
            q.push({cx+1, cy});
            grid[cx+1][cy].second = false;
        }
        if (cy > 0 && !grid[cx][cy-1].second) {
            q.push({cx, cy-1});
            grid[cx][cy-1].second = false;
        }
        if (cy < grid[0].size() - 1 && !grid[cx][cy+1].second) {
            q.push({cx, cy+1});
            grid[cx][cy+1].second = false;
        }
    }
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    grid.resize(h, vector<pair<Node, bool>>(w));
    visited.resize(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = {Node{i, j}, true};
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (grid[r][c].second) {
            grid[r][c].second = false;
        } else {
            destroyWalls(r, c);
        }
    }

    int remainingWalls = 0;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell.second) {
                ++remainingWalls;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}