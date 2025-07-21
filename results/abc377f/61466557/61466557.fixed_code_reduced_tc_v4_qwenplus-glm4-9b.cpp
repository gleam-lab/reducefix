#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<int, int>> rows, cols, diag1, diag2;

    // Collect the pieces' rows, columns, and diagonals
    for (auto& p : pieces) {
        rows.insert({p.first, p.first});
        cols.insert({p.second, p.second});
        diag1.insert({p.first - p.second, p.first + p.second});
        diag2.insert({p.first + p.second, p.first - p.second});
    }

    long long ans = n * n;

    // Subtract the number of squares taken by rows and columns
    for (auto& r : rows) ans -= r.second - r.first + 1;
    for (auto& c : cols) ans -= c.second - c.first + 1;

    // Subtract the number of squares taken by diagonals
    for (auto& d : diag1) {
        long long min_d = d.first < d.second ? d.first : d.second;
        long long max_d = d.first > d.second ? d.first : d.second;
        ans -= min_d - 1; // Subtract from the start of the diagonal
        ans += (max_d - min_d - 1) * n; // Add the squares in the middle
        ans -= (max_d - min_d) % 2; // Subtract the last square if it's not in the middle
    }
    for (auto& d : diag2) {
        long long min_d = d.first < d.second ? d.first : d.second;
        long long max_d = d.first > d.second ? d.first : d.second;
        ans -= min_d - 1; // Subtract from the start of the diagonal
        ans += (max_d - min_d - 1) * n; // Add the squares in the middle
        ans -= (max_d - min_d) % 2; // Subtract the last square if it's not in the middle
    }

    cout << ans << endl;

    return 0;
}