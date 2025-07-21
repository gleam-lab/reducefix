#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Section {
    int elevation, x, y;
};

bool operator<(const Section &a, const Section &b) {
    return a.elevation < b.elevation;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));
    priority_queue<Section> pq;

    // Read the elevation map and initialize the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Add edges to the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W - 1], i, W - 1});
        used[i][0] = 1;
        used[i][W - 1] = 1;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H - 1][j], H - 1, j});
        used[0][j] = 1;
        used[H - 1][j] = 1;
    }

    int remaining_area = H * W;
    while (!pq.empty()) {
        Section current = pq.top();
        pq.pop();
        remaining_area--;

        // Check the neighboring sections and add them to the queue if they will sink
        for (int d = 0; d < 4; ++d) {
            int ny = current.y + (d == 0) - (d == 2);
            int nx = current.x + (d == 1) - (d == 3);
            if (ny >= 0 && ny < H && nx >= 0 && nx < W && used[ny][nx] == 0) {
                if (chmax(used[ny][nx], 1)) {
                    pq.push({A[ny][nx], ny, nx});
                }
            }
        }
    }

    // Output the remaining area for each year
    for (int i = 1; i <= Y; ++i) {
        cout << remaining_area << endl;
    }

    return 0;
}