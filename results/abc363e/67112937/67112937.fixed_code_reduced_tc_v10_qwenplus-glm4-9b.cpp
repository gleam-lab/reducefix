#include <iostream>
#include <vector>
#include <set>

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

    multiset<pair<int, int>> remainingAreas; // pair<elevation, coordinates>

    // Initialize the set with all the original areas
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingAreas.insert({island[i][j], i * W + j});
        }
    }

    for (int year = 0; year < Y; ++year) {
        set<pair<int, int>> newRemainingAreas;

        // Expand the sea level from the edges inward
        for (int j = 0; j < W; ++j) {
            if (island[0][j] <= year) {
                for (int i = 0; i < H; ++i) {
                    island[i][j] = min(island[i][j], year);
                    newRemainingAreas.insert({island[i][j], i * W + j});
                }
            }
            if (island[H-1][j] <= year) {
                for (int i = 0; i < H; ++i) {
                    island[i][j] = min(island[i][j], year);
                    newRemainingAreas.insert({island[i][j], i * W + j});
                }
            }
        }

        for (int i = 0; i < H; ++i) {
            if (island[i][0] <= year) {
                for (int j = 0; j < W; ++j) {
                    island[i][j] = min(island[i][j], year);
                    newRemainingAreas.insert({island[i][j], i * W + j});
                }
            }
            if (island[i][W-1] <= year) {
                for (int j = 0; j < W; ++j) {
                    island[i][j] = min(island[i][j], year);
                    newRemainingAreas.insert({island[i][j], i * W + j});
                }
            }
        }

        // Calculate the area that remains above sea level
        int area = 0;
        for (auto& area : newRemainingAreas) {
            if (area.first > year) {
                area.first -= year; // Adjust the elevation
                area.second = i * W + j;
                area.first += newRemainingAreas.count({area.first, area.second});
            }
        }

        cout << area << "\n";
    }

    return 0;
}