#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// Function to check if a point is within the bounds of the grid
bool is_valid(int x, int y, int N) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

// Function to add capturing cells for a piece at (i, j)
void add_capturing_cells(vector<unordered_set<Point>>& grid, int i, int j, int N) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int k = 0; k < 8; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (is_valid(nx, ny, N)) {
            grid[nx].insert({ny});
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<unordered_set<Point>> grid(N);
    vector<Point> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        pieces[i] = {a, b};
        add_capturing_cells(grid, a, b, N);
    }

    // Calculate the number of empty cells that are not blocked
    unordered_set<Point> blocked_cells;
    for (const auto& p : pieces) {
        blocked_cells.insert({p.x, p.y});
    }
    for (int i = 0; i < N; ++i) {
        for (const auto& p : grid[i]) {
            blocked_cells.insert({p.x, p.y});
        }
    }

    int empty_cells = N * N - blocked_cells.size();
    cout << empty_cells << endl;
    return 0;
}