#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Function to check if a position is within bounds
bool inBounds(int x, int y, int n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }

    set<int> rows, cols, diags, adiags;

    // Populate sets with positions of existing pieces
    for (const auto &p : q) {
        rows.insert(p.first);
        cols.insert(p.second);
        diags.insert(p.first - p.second);
        adiags.insert(p.first + p.second);
    }

    // Calculate the number of valid positions
    int valid_positions = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!inBounds(i, j, n)) continue;
            if (rows.count(i) || cols.count(j) || diags.count(i - j) || adiags.count(i + j)) continue;
            ++valid_positions;
        }
    }

    cout << valid_positions << endl;

    return 0;
}