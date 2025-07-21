#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int D[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> available;

    // Collect all occupied squares and their attackable squares
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        available.insert({a - 1, b - 1}); // Convert to 0-indexed

        for (int d = 0; d < 8; ++d) {
            long long dx = a - 1 + D[d][0];
            long long dy = b - 1 + D[d][1];
            // Check if within bounds
            if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                available.insert({dx, dy});
            }
        }
    }

    // Count all possible squares to place the new piece
    long long totalplets = n * n;
    for (const auto& p : available) {
        totalplets--;
    }

    cout << totalplets << endl;
}