#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAXN = 1005;
const int MOD = 1e9 + 7;

int H, W, Y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

// Direction vectors for BFS (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Structure to represent a cell in the priority queue
struct Cell {
    int r, c, val;
    bool operator<(const Cell& other) const {
        return val > other.val; // Min-heap based on elevation
    }
};

// For each year, we want to know how many cells are still above water
int area[MAXN * MAXN]; 

// Function to perform multi-source BFS from the boundary
void bfs(priority_queue<Cell>& pq, int max_level) {
    int current_area = H * W;
    int* result = new int[max_level + 2];

    // Initialize all areas to be full at first
    for (int i = 0; i <= max_level; ++i) {
        result[i] = H * W;
    }

    while (!pq.empty()) {
        Cell curr = pq.top();
        pq.pop();

        // If elevation is higher than any possible Y, skip
        if (curr.val > max_level) continue;

        // For all years up to max_level greater than curr.val, reduce area
        for (int y = curr.val; y <= max_level; ++y) {
            result[y]--;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = curr.r + dx[d];
            int nc = curr.c + dy[d];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                visited[nr][nc] = true;
                Cell next = {nr, nc, grid[nr][nc]};
                pq.push(next);
            }
        }
    }

    // Output results for years 1 to Y
    for (int y = 1; y <= Y; ++y) {
        cout << result[y] << "\n";
    }

    delete[] result;
}

signed main() {
    close;
    cin >> H >> W >> Y;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // Priority queue to store boundary cells
    priority_queue<Cell> pq;

    // Mark and push boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    bfs(pq, Y);

    return 0;
}