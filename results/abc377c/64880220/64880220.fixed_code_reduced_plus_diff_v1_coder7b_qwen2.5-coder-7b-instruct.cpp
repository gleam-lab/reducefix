#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Directions for capturing moves
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    set<pair<long long, long long>> occupied;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }
    
    set<pair<long long, long long>> unsafe;
    for (auto& pos : occupied) {
        for (auto& dir : directions) {
            long long x = pos.first + dir.first;
            long long y = pos.second + dir.second;
            if (x > 0 && x <= n && y > 0 && y <= n) {
                unsafe.insert({x, y});
            }
        }
    }
    
    long long safe_count = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!occupied.count({i, j}) && !unsafe.count({i, j})) {
                ++safe_count;
            }
        }
    }
    
    cout << safe_count << endl;
    
    return 0;
}