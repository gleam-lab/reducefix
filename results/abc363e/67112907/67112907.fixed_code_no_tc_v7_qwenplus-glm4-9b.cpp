#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<pair<int, Pair>, vector<pair<int, Pair>>, greater<pair<int, Pair>>> pq;

    // Initialize the priority queue and visited array
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Mark all the cells that are on the edge or directly on the sea level
    for (int i = 0; i < H; i++) {
        visited[i][0] = visited[i][W - 1] = true;
        if (i == 0 || i == H - 1) {
            for (int j = 1; j < W - 1; j++) {
                visited[i][j] = true;
                pq.push({A[i][j], {i, j}});
            }
        } else {
            pq.push({A[i][0], {i, 0}});
            pq.push({A[i][W - 1], {i, W - 1}});
        }
    }
    for (int j = 1; j < W; j++) {
        pq.push({A[0][j], {0, j}});
        pq.push({A[H - 1][j], {H - 1, j}});
    }

    int remainingArea = H * W;
    while (!pq.empty()) {
        auto [h, p] = pq.top();
        pq.pop();
        if (h > Y) {
            remainingArea--;
            continue;
        }
        if (visited[p.x][p.y]) {
            continue;
        }
        visited[p.x][p.y] = true;
        remainingArea--;

        // Check the neighbors
        if (p.x > 0) pq.push({A[p.x - 1][p.y], {p.x - 1, p.y}});
        if (p.x < H - 1) pq.push({A[p.x + 1][p.y], {p.x + 1, p.y}});
        if (p.y > 0) pq.push({A[p.x][p.y - 1], {p.x, p.y - 1}});
        if (p.y < W - 1) pq.push({A[p.x][p.y + 1], {p.x, p.y + 1}});
    }

    for (int year = 0; year < Y; year++) {
        cout << remainingArea << '\n';
    }

    return 0;
}