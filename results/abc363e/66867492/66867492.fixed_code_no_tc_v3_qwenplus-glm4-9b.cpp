#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Priority queue to store the elements to be processed along with their coordinates and sea level
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], {i, 0}}); // Top of the island
        pq.push({A[i][W - 1], {i, W - 1}}); // Bottom of the island
        used[i][0] = 1;
        used[i][W - 1] = 1;
    }

    for (int j = 1; j < W - 1; ++j) {
        pq.push({A[0][j], {0, j}}); // Left edge of the island
        pq.push({A[H - 1][j], {H - 1, j}}); // Right edge of the island
        used[0][j] = 1;
        used[H - 1][j] = 1;
    }

    // Variable to keep track of the area of the island above sea level
    int ans = H * W;

    // Process the elements in the priority queue
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto top = pq.top();
            pq.pop();
            int r = top.second.first;
            int c = top.second.second;
            // Mark the section as used
            used[r][c] = 1;
            // Mark adjacent sections as used if their elevation is less than or equal to the current sea level
            for (int d = 0; d < 4; ++d) {
                int nr = r + (d == 0 ? 1 : (d == 1 ? 0 : -1));
                int nc = c + (d == 2 ? 1 : (d == 3 ? 0 : -1));
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && A[nr][nc] <= year && !used[nr][nc]) {
                    used[nr][nc] = 1;
                    pq.push({A[nr][nc], {nr, nc}});
                }
            }
            // Decrease the area of the island
            --ans;
        }
        cout << ans << endl;
    }

    return 0;
}