#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000000;

vector<int> rows, cols, ups, downs;

bool isValid(int n, int m, vector<pair<int, int>>& pieces) {
    // Collect all unique rows, columns, and diagonals
    set<int> rowSet, colSet, upSet, downSet;
    for (auto& p : pieces) {
        rowSet.insert(p.first);
        colSet.insert(p.second);
        upSet.insert(p.first + p.second);
        downSet.insert(p.first - p.second);
    }

    // Convert sets to vectors for easier access
    rows.assign(rowSet.begin(), rowSet.end());
    cols.assign(colSet.begin(), colSet.end());
    ups.assign(upSet.begin(), upSet.end());
    downs.assign(downSet.begin(), downSet.end());

    // Initialize threat arrays
    vector<bool> rowThreat(n + 1, false);
    vector<bool> colThreat(n + 1, false);
    vector<bool> upThreat(2 * n + 1, false);
    vector<bool> downThreat(2 * n + 1, false);

    // Mark threats
    for (auto& p : pieces) {
        rowThreat[p.first] = true;
        colThreat[p.second] = true;
        upThreat[p.first + p.second] = true;
        downThreat[p.first - p.second] = true;
    }

    // Count valid squares
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!rowThreat[i] && !colThreat[j] && !upThreat[i + j] && !downThreat[i - j]) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << isValid(n, m, pieces) << endl;
    return 0;
}