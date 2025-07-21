#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<long long, long long>> rows, cols, diag1, diag2;

    // Collect threatened positions
    for (auto &p : pieces) {
        rows.insert({p.first, 1});
        cols.insert({p.second, 1});
        diag1.insert({p.first - p.second, 1});
        diag2.insert({p.first + p.second, 1});
    }

    long long total_cells = n * n;
    long long threatened_cells = 0;

    // Count threatened cells
    for (auto &p : pieces) {
        threatened_cells += 1; // This piece itself
        if (rows.count({p.first, 0})) threatened_cells += n; // Entire row
        if (cols.count({p.second, 0})) threatened_cells += n; // Entire column
        if (diag1.count({p.first - p.second, 0})) threatened_cells += n; // Entire diagonal (p1, p2)
        if (diag2.count({p.first + p.second, 0})) threatened_cells += n; // Entire diagonal (p2, p3)
    }

    // Subtract threatened cells from the total
    cout << total_cells - threatened_cells;
    return 0;
}