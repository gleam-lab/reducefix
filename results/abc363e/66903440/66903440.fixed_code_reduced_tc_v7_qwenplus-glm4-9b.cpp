#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w, y;
int grid[1001][1001];

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    // Priority queue to manage sinking
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue for the first year
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] <= 1) {
                pq.push({grid[i][j], {i, j}});
            }
        }
    }

    ll remaining_area = h * w;

    for (int year = 1; year <= y; year++) {
        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            int i = pos.first;
            int j = pos.second;
            remaining_area--;

            // Check neighbors
            if (i > 0 && grid[i - 1][j] <= year) pq.push({grid[i - 1][j], {i - 1, j}});
            if (i < h - 1 && grid[i + 1][j] <= year) pq.push({grid[i + 1][j], {i + 1, j}});
            if (j > 0 && grid[i][j - 1] <= year) pq.push({grid[i][j - 1], {i, j - 1}});
            if (j < w - 1 && grid[i][j + 1] <= year) pq.push({grid[i][j + 1], {i, j + 1}});
        }

        cout << remaining_area << endl;
        
        // Increase the sea level for the next year
        if (!pq.empty()) {
            auto [top_height, top_pos] = pq.top();
            pq.pop();
            pq.push({top_height + 1, top_pos});
        }
    }

    return 0;
}