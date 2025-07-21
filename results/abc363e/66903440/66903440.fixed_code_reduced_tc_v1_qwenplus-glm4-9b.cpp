#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int total_area = 0;

    // Initialize the priority queue with the edges of the grid
    for (int i = 0; i < H; ++i) {
        pq.push({-A[i][0], {i, 0}}); // West edge
        pq.push({-A[i][W-1], {i, W-1}}); // East edge
    }
    for (int j = 0; j < W; ++j) {
        pq.push({-A[0][j], {0, j}}); // North edge
        pq.push({-A[H-1][j], {H-1, j}}); // South edge
        total_area += A[H-1][j]; // Count the area of the bottom row
    }
    total_area -= A[0][0]; // Subtract the area of the top-left corner twice counted

    // Process the priority queue
    while (!pq.empty()) {
        auto [height, {y, x}] = pq.top();
        pq.pop();
        if (visited[y][x]) continue;
        visited[y][x] = true;
        total_area -= A[y][x]; // Subtract the area of the sunk cell

        // Check the neighbors
        if (y > 0) pq.push({-A[y-1][x], {y-1, x}}); // North
        if (y < H-1) pq.push({-A[y+1][x], {y+1, x}}); // South
        if (x > 0) pq.push({-A[y][x-1], {y, x-1}}); // West
        if (x < W-1) pq.push({-A[y][x+1], {y, x+1}}); // East
    }

    // Output the remaining area for each year
    for (int y = 0; y < Y; ++y) {
        cout << total_area << endl;
    }

    return 0;
}