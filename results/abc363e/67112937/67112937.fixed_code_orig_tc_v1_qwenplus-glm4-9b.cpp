#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> island(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> island[i][j];
        }
    }

    int sea_level = 0;
    int remaining_area = H * W;
    queue<pair<int, int>> sink_queue;

    for (int year = 0; year < Y; ++year) {
        vector<vector<bool>> submerged(H, vector<bool>(W, false));
        int submerged_area = 0;
        queue<pair<int, int>> current_sinks;

        // Find all submerged sections at the current year
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && island[i][j] <= sea_level) {
                    submerged[i][j] = true;
                    ++submerged_area;
                }
                if (submerged[i][j]) {
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + (k == 0 ? -1 : (k == 1 ? 1 : 0));
                        int nj = j + (k == 2 ? -1 : (k == 3 ? 1 : 0));
                        if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj] && island[ni][nj] <= sea_level) {
                            current_sinks.push({ni, nj});
                            submerged[ni][nj] = true;
                            ++submerged_area;
                        }
                    }
                }
            }
        }

        // Update the remaining area
        remaining_area -= submerged_area;

        // Prepare for the next year
        for (auto& sink : current_sinks) {
            sink_queue.push(sink);
        }
        sea_level++;
    }

    // Output the remaining area for each year
    for (int year = 0; year < Y; ++year) {
        cout << remaining_area << endl;
    }

    return 0;
}