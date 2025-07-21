#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<pair<long long, long long>> occupied;
    occupied.reserve(n * n);
    for (const auto& p : pieces) {
        occupied.emplace_back(p.first, p.second);
    }

    sort(occupied.begin(), occupied.end());

    long long free_cells = n * n;
    for (int i = 0; i < m; ++i) {
        free_cells -= 8; // Each piece can potentially free 8 cells
        long long x = pieces[i].first, y = pieces[i].second;
        bool captured[8] = {false};

        // Check the moves of the piece
        for (int dir = 0; dir < 8; ++dir) {
            long long nx = x + (dir & 1) * 2, ny = y + (dir & 2) * 2;
            // Check if the resulting cell is within bounds
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                auto it = lower_bound(occupied.begin(), occupied.end(), {nx, ny});
                if (it != occupied.begin() && prev(it)->first == nx) { // Same column, check above/below
                    if (abs(it->second - ny) <= 2) captured[dir] = true;
                } else if (it != occupied.end() && it->first == nx) { // Same row, check left/right
                    if (abs(it->second - ny) <= 2) captured[dir] = true;
                }
            }
        }

        // Count non-captured cells
        for (int dir = 0; dir < 8; ++dir) {
            if (!captured[dir]) free_cells++;
        }
    }

    cout << free_cells << endl;
    return 0;
}