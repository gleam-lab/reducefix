#include <bits/stdc++.h>
using namespace std;
#define int long long

int h, w, y;
int grid[h][w];
bool vis[h][w];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void enqueue(int x, int y) {
    if (x >= 0 and x < h and y >= 0 and y < w and !vis[x][y]) {
        pq.push({grid[x][y], x * w + y});
        vis[x][y] = true;
    }
}

int main() {
    // Input reading
    // Initialize variables
    // Enqueue the borders of the island

    while (!pq.empty()) {
        auto [elevation, index] = pq.top();
        pq.pop();

        // Check if current cell elevation is less than or equal to level
        if (elevation <= level) {
            // Process adjacent cells
            int x = index / w;
            int y = index % w;
            enqueue(x - 1, y);
            enqueue(x + 1, y);
            enqueue(x, y - 1);
            enqueue(x, y + 1);
        }
    }

    // Calculate the remaining area above sea level
    // Output the result
}