#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dir[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    set<pair<long long, long long>> capture_area;

    // Read pieces and calculate the capture area
    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        pieces[i] = {x - 1, y - 1}; // Convert to zero-indexed
        for (auto& dir : dir) {
            if (x + dir[0] < n && y + dir[1] < n) {
                capture_area.insert({x + dir[0], y + dir[1]});
            }
        }
    }

    // Calculate the number of empty cells not in any capture area
    long long total_cells = n * n;
    long long captured_cells = capture_area.size();

    // Each captured cell is surrounded by 4 cells that can also be captured
    // except for the corners which are surrounded by 4, 3, 3, 3
    long long additional_captures = 0;
    for (const auto& p : capture_area) {
        long long x = p.first, y = p.second;
        bool corner = (x == 0 || x == n - 1) && (y == 0 || y == n - 1);
        if (!corner) {
            additional_captures += 4;
        } else {
            additional_captures += 3; // Only 3 additional captures for 2 corners
        }
    }

    cout << total_cells - captured_cells - additional_captures << endl;

    return 0;
}