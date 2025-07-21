#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000

int n, m;
vector<int> rows[MAX_N + 1], cols[MAX_N + 1], diags[MAX_N * 2], adiags[MAX_N * 2];

bool canPlace(int x, int y) {
    return !(rows[y].size() && rows[y].back() == x) &&
           !(cols[x].size() && cols[x].back() == y) &&
           !(diags[x + y].size() && diags[x + y].back() == y) &&
           !(adiags[x - y + n].size() && adiags[x - y + n].back() == y);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        rows[y].push_back(x);
        cols[x].push_back(y);
        diags[x + y].push_back(y);
        adiags[x - y + n].push_back(y);
    }

    for (int i = 1; i <= n; ++i) {
        sort(rows[i].begin(), rows[i].end());
        sort(cols[i].begin(), cols[i].end());
        sort(diags[i].begin(), diags[i].end());
        sort(adiags[i].begin(), adiags[i].end());
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (canPlace(i, j)) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}