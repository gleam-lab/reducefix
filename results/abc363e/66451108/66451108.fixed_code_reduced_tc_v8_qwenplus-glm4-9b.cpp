#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Section {
    int x, y;
};
struct Comparator {
    bool operator()(Section a, Section b) {
        return a.x * 1000 + a.y < b.x * 1000 + b.y; // Use a stable order to maintain priority
    }
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    // Read grid elevations
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Section, vector<Section>, Comparator> pq;
    vector<vector<bool>> canSink(h, vector<bool>(w, false));

    // Initialize the priority queue with the first year's sinking sections
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 0 || (i == 0 || j == 0 || i == h - 1 || j == w - 1)) {
                canSink[i][j] = true;
                pq.push({i, j});
            }
        }
    }

    int totalArea = h * w;
    for (int year = 1; year <= y; ++year) {
        while (!pq.empty()) {
            Section curr = pq.top();
            pq.pop();

            // Check neighbors and mark as sinking if needed
            if (curr.x > 0 && curr.y > 0 && !visited[curr.x - 1][curr.y - 1] && grid[curr.x - 1][curr.y - 1] != 0 && canSink[curr.x - 1][curr.y - 1]) {
                visited[curr.x - 1][curr.y - 1] = true;
                totalArea--;
                pq.push({curr.x - 1, curr.y - 1});
            }
            if (curr.x < h - 1 && curr.y > 0 && !visited[curr.x + 1][curr.y - 1] && grid[curr.x + 1][curr.y - 1] != 0 && canSink[curr.x + 1][curr.y - 1]) {
                visited[curr.x + 1][curr.y - 1] = true;
                totalArea--;
                pq.push({curr.x + 1, curr.y - 1});
            }
            // Similar checks for other directions (right, bottom, top, left)
        }
        cout << totalArea << endl;
        // Update canSink for the next year
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (canSink[i][j]) {
                    canSink[i][j] = grid[i][j] == 0 || (i == 0 || j == 0 || i == h - 1 || j == w - 1);
                }
            }
        }
    }
    
    return 0;
}