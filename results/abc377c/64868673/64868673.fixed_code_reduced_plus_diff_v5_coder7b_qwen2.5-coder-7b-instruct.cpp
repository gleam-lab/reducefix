#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    // Set to store positions of existing pieces
    set<pair<long long, long long>> pieces;
    
    // Directions for capturing moves
    vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Read positions of existing pieces
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    // Count valid empty squares
    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool can_place = true;
            for(auto &dir : directions) {
                long long x = i + dir.first;
                long long y = j + dir.second;
                if(x >= 1 && x <= n && y >= 1 && y <= n && pieces.find({x, y}) != pieces.end()) {
                    can_place = false;
                    break;
                }
            }
            if(can_place) {
                count++;
            }
        }
    }

    // Output the result
    cout << n * n - count << endl;

    return 0;
}