#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> island(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> island[i][j];
        }
    }

    while (y--) {
        vector<vector<int>> copy = island; // Copy for each year
        bool changed = true;
        
        while (changed) {
            changed = false;
            vector<vector<int>> will_sink(h, vector<int>(w, 0));

            // Determine which cells will sink
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (copy[i][j] <= (island[h][w] + 1)) {
                        will_sink[i][j] = 1;
                        changed = true;
                    }
                }
            }

            // Update the island
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (will_sink[i][j] == 1) {
                        island[i][j]--;
                    }
                }
            }

            // Reset the will_sink matrix for the next iteration
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    will_sink[i][j] = 0;
                }
            }
        }

        // Output the remaining area above water
        int remaining_area = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (island[i][j] > 0) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}