#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

struct State {
    int height, row, col;
    State(int h, int r, int c) : height(h), row(r), col(c) {}
    bool operator>(const State& other) const {
        return height > other.height;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<State, vector<State>, greater<State>> pq;

    // Initialize the queue with the borders
    for (int i = 0; i < H; ++i) {
        pq.push(State(grid[i][0], i, 0));
        pq.push(State(grid[i][W - 1], i, W - 1));
        visited[i][0] = visited[i][W - 1] = true;
    }

    for (int j = 0; j < W; ++j) {
        pq.push(State(grid[0][j], 0, j));
        pq.push(State(grid[H - 1][j], H - 1, j));
        visited[0][j] = visited[H - 1][j] = true;
    }

    int remainingArea = H * W;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.height > Y) {
            remainingArea--;
        }
    }

    cout << remainingArea << '\n';
    return 0;
}