#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store positions of all pieces
    unordered_set<long long> pieces;
    
    // Directions for capturing moves
    vector<pair<int, int>> directions = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2},
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
    };
    
    // Read the positions of all pieces
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert((a - 1) * n + b); // Convert 2D to 1D index
    }
    
    // Function to check if a position is within bounds
    auto isValid = [&](long long x, long long y) {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    };
    
    // Count valid empty squares
    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool isEmpty = true;
            for(auto& dir : directions) {
                long long x = i + dir.first;
                long long y = j + dir.second;
                if(isValid(x, y) && pieces.count((x - 1) * n + y)) {
                    isEmpty = false;
                    break;
                }
            }
            if(isEmpty) {
                ++count;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}