#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Directions for knight moves
    vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Set to store all unsafe positions
    set<pair<long long, long long>> unsafe_positions;

    // Read the positions of the existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        for (auto& dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                unsafe_positions.insert({x, y});
            }
        }
    }

    // Calculate the number of safe positions
    long long total_positions = n * n;
    long long safe_positions = total_positions - unsafe_positions.size();

    cout << safe_positions << endl;

    return 0;
}