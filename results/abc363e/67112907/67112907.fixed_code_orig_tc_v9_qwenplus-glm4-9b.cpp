#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> island(H, vector<int>(W));
    
    // Read the heights of the island
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> island[i][j];
        }
    }
    
    // Calculate the initial area of the island that is above sea level
    int remaining_area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (island[i][j] > 0) {
                remaining_area++;
            }
        }
    }

    // Simulate the sea level rise for Y years
    for (int year = 0; year < Y; year++) {
        // For this year, every section below sea level becomes submerged
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (island[i][j] <= year) {
                    remaining_area--;
                }
            }
        }
        cout << remaining_area << endl;
    }
    
    return 0;
}