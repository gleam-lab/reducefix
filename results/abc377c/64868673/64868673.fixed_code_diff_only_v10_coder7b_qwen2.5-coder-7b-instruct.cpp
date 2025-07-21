#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store positions of existing pieces
    set<pair<long long, long long>> pieces;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    // Directions for capturing pieces
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Set to store positions that can be captured
    set<pair<long long, long long>> capturable;

    // Mark all positions that can be captured by existing pieces
    for (const auto& [a, b] : pieces) {
        for (const auto& [da, db] : directions) {
            long long x = a + da;
            long long y = b + db;
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                capturable.insert({x, y});
            }
        }
    }

    // Calculate the number of empty squares that cannot be captured
    long long total_squares = n * n;
    long long empty_squares = total_squares - capturable.size();
    cout << empty_squares << endl;

    return 0;
}