#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    // Directions a piece can move to capture another piece
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Set to keep track of all positions that cannot be placed upon
    unordered_set<long long> capturedPositions;

    // Process each piece
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Convert 1-based index to 0-based index
        --a, --b;
        
        // Mark the positions that can be captured by this piece
        for (const auto& dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            
            // Check if the position is within bounds
            if (x >= 0 && x < n && y >= 0 && y < n) {
                capturedPositions.insert(x * n + y);
            }
        }
    }

    // Calculate the number of available positions
    long long totalPositions = n * n;
    long long occupiedPositions = capturedPositions.size();
    
    // The number of empty squares is the total positions minus the occupied positions
    cout << totalPositions - occupiedPositions << endl;

    return 0;
}