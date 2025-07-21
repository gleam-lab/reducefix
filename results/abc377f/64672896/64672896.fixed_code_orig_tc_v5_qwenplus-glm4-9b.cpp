#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<pair<int, int>> diag1, diag2, row, col;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        diag1.push_back({x + y, x - y});
        diag2.push_back({x - y, x + y});
        row.push_back({x, 0});
        col.push_back({y, 1});
    }

    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    set<int> captured;
    captured.insert(0);

    // Calculate captured rows, columns and diagonals
    for (auto& d : diag1) {
        auto it = lower_bound(diag2.begin(), diag2.end(), d);
        if (it != diag2.begin()) {
            --it;
            if (d.first - it->second == 2) {
                captured.insert(d.first - it->second);
            }
        }
        it = upper_bound(diag2.begin(), diag2.end(), d);
        if (it != diag2.end()) {
            if (d.first - it->second == 2) {
                captured.insert(d.first - it->second);
            }
        }
    }

    for (auto& r : row) {
        captured.insert(r.first);
    }
    for (auto& c : col) {
        captured.insert(c.first);
    }

    // Calculate the number of safe squares
    int safe_squares = n * n;
    for (auto& c : captured) {
        if (c < 1 || c > n) continue;
        safe_squares -= (n - c + 1) * (n - c + 1);
    }

    cout << safe_squares << endl;
    return 0;
}