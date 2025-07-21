#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 1000

vector<vector<int>> grid[MAXN];
int h, w, y;

struct Section {
    int elevation;
    int x, y;
};

struct Compare {
    bool operator()(const Section& a, const Section& b) {
        return a.elevation > b.elevation;
    }
};

void processSinking(int seaLevel) {
    priority_queue<Section, vector<Section>, Compare> pq;
    int totalSunk = 0;

    // Push all sections on the edge of the grid into the priority queue
    for (int i = 0; i < h; i++) {
        pq.push({grid[i][0].elevation, i, 0});
        pq.push({grid[i][w - 1].elevation, i, w - 1});
        totalSunk += grid[i][0].elevation <= seaLevel || grid[i][w - 1].elevation <= seaLevel;
    }
    for (int j = 1; j < w - 1; j++) {
        pq.push({grid[0][j].elevation, 0, j});
        pq.push({grid[h - 1][j].elevation, h - 1, j});
        totalSunk += grid[0][j].elevation <= seaLevel || grid[h - 1][j].elevation <= seaLevel;
    }

    // Process the sections in the priority queue
    while (!pq.empty()) {
        Section current = pq.top();
        pq.pop();

        // Check the neighbors
        vector<pair<int, int>> neighbors = {{current.x, current.y - 1}, {current.x, current.y + 1}, {current.x - 1, current.y}, {current.x + 1, current.y}};
        for (auto& neighbor : neighbors) {
            int nx = neighbor.first, ny = neighbor.second;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny].elevation <= seaLevel) {
                pq.push({grid[nx][ny].elevation, nx, ny});
                totalSunk++;
            }
        }
    }

    // Output the remaining area
    cout << (h * w - totalSunk) << endl;
}

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; i++) {
        grid[i].resize(w);
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j].elevation;
            grid[i][j].x = i;
            grid[i][j].y = j;
        }
    }

    for (int year = 1; year <= y; year++) {
        processSinking(year);
    }

    return 0;
}