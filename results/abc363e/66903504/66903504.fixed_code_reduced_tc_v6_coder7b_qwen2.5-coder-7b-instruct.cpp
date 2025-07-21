#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Sort all heights
    vector<int> heights;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            heights.push_back(A[i][j]);
        }
    }
    sort(heights.begin(), heights.end());

    // Initialize the result array
    vector<int> result(Y + 1, H * W);

    // Iterate over each unique height
    for (int k = 0; k < heights.size(); ++k) {
        int height = heights[k];
        int count = 0;
        
        // Count how many cells are below or equal to the current height
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= height) {
                    count++;
                }
            }
        }

        // Update the result array for all levels up to the current height
        for (int y = 1; y <= Y && y <= height; ++y) {
            result[y] -= count;
        }
    }

    // Output the results
    for (int y = 1; y <= Y; ++y) {
        cout << result[y] << endl;
    }

    return 0;
}