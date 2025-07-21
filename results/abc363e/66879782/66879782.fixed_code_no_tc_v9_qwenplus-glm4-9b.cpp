#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int H, W, Y;
vector<vector<int>> height, sink;

struct Pair {
    int r, c, h;
    bool operator<(const Pair& other) const {
        return h < other.h;
    }
};

int main() {
    cin >> H >> W >> Y;
    height.resize(H, vector<int>(W));
    sink.resize(H, vector<int>(W));
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    // Initialize the height and sink arrays
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> height[i][j];
            sink[i][j] = INT_MAX;
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                sink[i][j] = height[i][j];
                pq.push({i, j, height[i][j]});
            }
        }
    }

    // Perform the flooding simulation
    while (!pq.empty()) {
        Pair p = pq.top();
        pq.pop();
        int r = p.r, c = p.c, h = p.h;
        if (sink[r][c] < h) continue; // Skip if already flooded
        sink[r][c] = h;
        if (r > 0) pq.push({r - 1, c, min(height[r - 1][c], h)});
        if (r + 1 < H) pq.push({r + 1, c, min(height[r + 1][c], h)});
        if (c > 0) pq.push({r, c - 1, min(height[r][c - 1], h)});
        if (c + 1 < W) pq.push({r, c + 1, min(height[r][c + 1], h)});
    }

    // Calculate the remaining area for each year
    vector<long long> remaining(H * W); // Max area that can be above water
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remaining[i * W + j] = min(height[i][j], min(i, j)) + min(H - 1 - i, W - 1 - j) - 1;
        }
    }

    long long total = 0;
    for (int i = 0; i < Y; ++i) {
        long long area = 0;
        for (int j = 0; j < remaining.size(); ++j) {
            if (remaining[j] > i) {
                area++;
            }
        }
        cout << area << '\n';
    }

    return 0;
}