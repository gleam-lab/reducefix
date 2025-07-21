#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3;

set<int> rows[MAX_N + 1];
set<int> cols[MAX_N + 1];
set<int> diags[2][MAX_N + 1]; // [0] for main diagonal, [1] for anti-diagonal

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows[y].insert(x);
        cols[x].insert(y);
        diags[0][x - y].insert(i);
        diags[1][x + y].insert(i);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool captured = false;
            if (!rows[j].empty()) {
                auto it = rows[j].upper_bound(i);
                if (it != rows[j].end() && *it == i) continue;
                if (it != rows[j].begin()) {
                    --it;
                    captured |= rows[j].size() - (*it <= i);
                }
            }
            if (!cols[i].empty()) {
                auto it = cols[i].upper_bound(j);
                if (it != cols[i].end() && *it == j) continue;
                if (it != cols[i].begin()) {
                    --it;
                    captured |= cols[i].size() - (*it <= j);
                }
            }
            if (!diags[0][i - j].empty()) {
                auto it = diags[0][i - j].upper_bound(pieces.size());
                if (it != diags[0][i - j].end() && *it == pieces.size()) continue;
                if (it != diags[0][i - j].begin()) {
                    --it;
                    captured |= diags[0][i - j].size() - (*it <= pieces.size());
                }
            }
            if (!diags[1][i + j].empty()) {
                auto it = diags[1][i + j].upper_bound(pieces.size());
                if (it != diags[1][i + j].end() && *it == pieces.size()) continue;
                if (it != diags[1][i + j].begin()) {
                    --it;
                    captured |= diags[1][i + j].size() - (*it <= pieces.size());
                }
            }
            if (!captured) ++ans;
        }
    }
    
    cout << ans << endl;
    return 0;
}