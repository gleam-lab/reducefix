#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()

int H, W, Y;
const int MAX_H = 1010;
const int MAX_W = 1010;

// Directions: up, right, down, left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// Struct for storing cell data
struct Cell {
    int r, c, h;
    bool operator<(const Cell& other) const {
        return h < other.h;
    }
};

// Comparator for priority queue
struct CompareCell {
    bool operator()(const Cell& a, const Cell& b) {
        return a.h > b.h;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Total number of cells
    int total = H * W;

    // Priority queue to process cells in increasing order of height
    priority_queue<Cell, vector<Cell>, CompareCell> pq;

    // Visited array to mark if a cell is submerged
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue with boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({i, j, A[i][j]});
                visited[i][j] = true;
            }
        }
    }

    // Prepare an array to store remaining area for each year
    vector<int> remaining(Y + 2, 0);
    remaining[0] = H * W;

    // Process cells in BFS fashion based on elevation
    while (!pq.empty()) {
        auto [r, c, h] = pq.top();
        pq.pop();

        // Determine the earliest year this cell can be submerged
        int year = h;

        if (year > Y) {
            // If elevation exceeds max years, it never submerges
            for (int y = 1; y <= Y; ++y) {
                remaining[y] = remaining[Y];
            }
            break;
        }

        // All future years up to `h` will have same count
        for (int y = 1; y <= min(Y, h); ++y) {
            if (remaining[y] == 0) {
                remaining[y] = remaining[y - 1] - 1;
            } else {
                remaining[y] = remaining[y];
            }
        }

        // Check neighbors and add unvisited ones to queue
        for (int d = 0; d < 4; ++d) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                visited[nr][nc] = true;
                pq.push({nr, nc, A[nr][nc]});
            }
        }
    }

    // Fill any missing values from previous years
    for (int y = 1; y <= Y; ++y) {
        if (remaining[y] == 0) {
            remaining[y] = remaining[y - 1];
        }
    }

    // Output results
    for (int y = 1; y <= Y; ++y) {
        cout << remaining[y] << "\n";
    }

    return 0;
}