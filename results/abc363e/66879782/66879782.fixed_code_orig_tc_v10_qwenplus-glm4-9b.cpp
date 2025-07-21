#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Priority queue to process cells by height
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Initialize the queue with border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i * W + j});
            }
        }
    }
    
    // Process cells in descending order of height
    while (!pq.empty()) {
        int h = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        int r = idx / W;
        int c = idx % W;
        // Check adjacent cells
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && A[nr][nc] <= h) {
                    pq.push({A[nr][nc], nr * W + nc});
                }
            }
        }
    }
    
    // Calculate the area of the island remaining after Y years
    long long area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            area += A[i][j];
        }
    }
    
    for (int i = 1; i <= Y; ++i) {
        cout << area << '\n';
        // Each year, the area remaining in the island decreases by the area of cells that would sink in the next year
        area -= (long long)H * W - (long long)H * W * (i + 1);
    }
    
    return 0;
}