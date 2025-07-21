#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store positions of existing pieces
    set<pair<long long, long long>> pieces;
    
    // Read positions of existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    // Directions for capturing moves
    vector<vector<long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Function to check if a position is within bounds and not occupied
    auto isValid = [&](long long x, long long y) {
        return x >= 1 && x <= n && y >= 1 && y <= n && pieces.find({x, y}) == pieces.end();
    };

    // Count valid positions
    long long count = 0;
    for (auto& [a, b] : pieces) {
        for (auto& dir : directions) {
            long long x = a + dir[0], y = b + dir[1];
            if (isValid(x, y)) {
                count++;
            }
        }
    }

    // Total empty positions minus the counted positions
    cout << n * n - m - count / 2 << endl;

    return 0;
}