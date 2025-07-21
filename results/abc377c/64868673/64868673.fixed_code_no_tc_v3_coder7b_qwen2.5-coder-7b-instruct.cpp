#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to keep track of occupied squares
    set<pair<long long, long long>> occupied;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    // Directions a knight can move
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Count valid positions
    long long valid_positions = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            bool is_valid = true;
            for (const auto& dir : directions) {
                long long ni = i + dir.first;
                long long nj = j + dir.second;
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= n) {
                    if (occupied.count({ni, nj})) {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (is_valid) {
                ++valid_positions;
            }
        }
    }

    // Output the result
    cout << valid_positions << endl;
    return 0;
}