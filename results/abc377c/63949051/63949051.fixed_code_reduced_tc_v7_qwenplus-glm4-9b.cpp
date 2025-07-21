#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define MAX_N 1000000000

void print_grid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (i == j || i + j == n + 1) ? 1 : 0 << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // To avoid duplicate checks and to handle the symmetric capturing area
    set<pair<int, int>> capture_area;
    for (auto& p : pieces) {
        int x = min(p.first, p.second);
        int y = max(p.first, p.second);
        // Capture range in the top-left quadrant
        for (int i = x; i <= x + 3 && i <= n; i++) {
            for (int j = y; j <= y + 1 && j <= n; j++) {
                capture_area.insert({i, j});
            }
        }
        // Capture range in the top-right quadrant
        for (int i = x; i <= x + 1 && i <= n; i++) {
            for (int j = y; j <= y + 3 && j <= n; j++) {
                capture_area.insert({i, j});
            }
        }
        // Capture range in the bottom-left quadrant
        for (int i = x; i <= x + 3 && i <= n; i++) {
            for (int j = y; j <= y + 1 && j <= n; j++) {
                capture_area.insert({n - j + 1, n - i + 1});
            }
        }
        // Capture range in the bottom-right quadrant
        for (int i = x; i <= x + 1 && i <= n; i++) {
            for (int j = y; j <= y + 3 && j <= n; j++) {
                capture_area.insert({n - j + 1, n - i + 1});
            }
        }
    }

    // Calculate the number of non-attackable cells
    long long non_attackable = capture_area.size();
    long long attackable_cells = (n * n) - non_attackable;

    // Calculate the number of cells that can be placed without being captured
    long long available_cells = (n * n) - attackable_cells;
    cout << available_cells << '\n';

    return 0;
}