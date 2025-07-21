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

    // Priority queue to simulate sinking process
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize the priority queue with edge sections and any sections that will sink immediately
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i * W}); // Leftmost column
        pq.push({A[i][W - 1], i * W + W - 1}); // Rightmost column
    }
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], j}); // Top row
        pq.push({A[H - 1][j], (H - 1) * W + j}); // Bottom row
    }

    // Simulate sinking process for each year
    for (int year = 1; year <= Y; ++year) {
        int remaining_area = 0;
        while (!pq.empty()) {
            int current_elev = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            // Check if the current section is still above sea level for this year
            if (current_elev > year) {
                // Count the remaining area for this section
                if (pos % W == 0) { // Leftmost column
                    remaining_area += (W - 1); // Only consider right adjacent section
                } else if (pos % W == W - 1) { // Rightmost column
                    remaining_area += (W - 1); // Only consider left adjacent section
                } else { // Middle columns
                    remaining_area += W; // Consider all adjacent sections
                }
            }

            // Check adjacent sections to see if they need to be added to the queue
            // ...
        }
        cout << remaining_area << endl;
    }

    return 0;
}