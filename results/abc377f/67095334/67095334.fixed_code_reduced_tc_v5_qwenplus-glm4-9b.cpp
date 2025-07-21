#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    map<int, set<int>> row_covered;
    map<int, set<int>> col_covered;
    map<int, set<int>> diag1_covered; // i+j
    map<int, set<int>> diag2_covered; // i-j

    // Read pieces and cover the corresponding rows, columns, and diagonals
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        row_covered[pieces[i].first].insert(pieces[i].second);
        col_covered[pieces[i].second].insert(pieces[i].first);
        diag1_covered[pieces[i].first + pieces[i].second].insert(pieces[i].second);
        diag2_covered[pieces[i].first - pieces[i].second].insert(pieces[i].second);
    }

    long long ans = n * n; // Total number of squares

    // Remove covered squares from the total
    for (auto& p : row_covered) {
        ans -= p.second.size();
    }
    for (auto& p : col_covered) {
        ans -= p.second.size();
    }
    for (auto& p : diag1_covered) {
        ans -= p.second.size();
    }
    for (auto& p : diag2_covered) {
        ans -= p.second.size();
    }

    // Output the result
    cout << ans << endl;

    return 0;
}