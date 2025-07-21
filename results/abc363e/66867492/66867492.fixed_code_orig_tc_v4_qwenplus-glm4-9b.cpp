#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Read elevation data
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Initialize the sea level
    int sea_level = 0;
    
    // Mark all sections at sea level or lower
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= sea_level) {
                visited[i][j] = true;
            }
        }
    }
    
    // Calculate the initial area above sea level
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }
    
    // Process each year
    for (int year = 1; year <= Y; ++year) {
        // Update sea level
        sea_level++;
        
        // Mark all sections that will sink this year
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= sea_level) {
                    visited[i][j] = true;
                }
            }
        }
        
        // Calculate the new remaining area
        int new_remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    new_remaining_area++;
                }
            }
        }
        
        // Output the new remaining area
        cout << new_remaining_area << endl;
    }
    
    return 0;
}