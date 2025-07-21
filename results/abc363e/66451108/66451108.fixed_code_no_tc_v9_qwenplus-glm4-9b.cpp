#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define H_MAX 1000
#define W_MAX 1000
#define Y_MAX 100000

int H, W, Y;
int A[H_MAX][W_MAX];

struct Cell {
    int x, y, height;
    Cell(int x, int y, int height) : x(x), y(y), height(height) {}
};

// Compare two cells by their height
struct Compare {
    bool operator()(const Cell& a, const Cell& b) {
        return a.height < b.height;
    }
};

void simulateFlood(int year) {
    priority_queue<Cell, vector<Cell>, Compare> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with all cells on the edges of the grid
    for (int i = 0; i < H; ++i) {
        pq.push(Cell(i, 0, A[i][0]));
        pq.push(Cell(i, W - 1, A[i][W - 1]));
        visited[i][0] = visited[i][W - 1] = true;
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.push(Cell(0, j, A[0][j]));
        pq.push(Cell(H - 1, j, A[H - 1][j]));
        visited[0][j] = visited[H - 1][j] = true;
    }

    int remainingArea = H * W;
    while (!pq.empty()) {
        int currentHeight = pq.top().height;
        pq.pop();

        if (currentHeight <= year) {
            remainingArea--;
            continue;
        }

        // Process all adjacent cells
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = pq.top().x + dx;
                int ny = pq.top().y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push(Cell(nx, ny, A[nx][ny]));
                }
            }
        }
    }

    cout << remainingArea << endl;
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < Y; ++i) {
        simulateFlood(i + 1);
    }

    return 0;
}