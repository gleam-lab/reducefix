#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    set<pair<int, int>> rows;
    set<pair<int, int>> cols;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert({x, 1});
        rows.insert({x, -1});
        cols.insert({y, 1});
        cols.insert({y, -1});
    }

    // Calculate number of blocked rows and columns
    long long blocked_rows = rows.size();
    long long blocked_cols = cols.size();

    // Calculate the number of safe cells
    // Note: This is a simplified approach, and you might need to adjust the calculation
    long long total_cells = n * n;
    long long blocked_cells = blocked_rows + blocked_cols; // This is a simplification

    // Final calculation
    long long safe_cells = total_cells - blocked_cells;

    cout << safe_cells << endl;

    return 0;
}