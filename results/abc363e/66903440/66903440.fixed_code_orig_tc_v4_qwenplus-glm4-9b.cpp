#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> F(H, vector<bool>(W, false));

    // Input the elevation of the cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Process each year
    for (int y = 1; y <= Y; ++y) {
        deque<pair<int, int>> queue;
        
        // Initialize the queue with cells that are currently at sea level
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] == y || A[i][j] + 1 == y) {
                    queue.push_back({i, j});
                    F[i][j] = true;
                }
            }
        }

        // Simulate the flood
        while (!queue.empty()) {
            auto [i, j] = queue.front();
            queue.pop_front();
            
            // Check all adjacent cells
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    int ni = i + k, nj = j + l;
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && !F[ni][nj] && A[ni][nj] < y) {
                        queue.push_back({ni, nj});
                        F[ni][nj] = true;
                    }
                }
            }
        }

        // Output the area of the island that is still above sea level
        int remaining_area = count_if(F.begin(), F.end(), [](bool x) { return !x; });
        cout << remaining_area << endl;
    }

    return 0;
}