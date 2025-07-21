#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e9 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<int> rows, cols, diags, anti_diags;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        anti_diags.insert(a - b);
    }

    ll total_positions = n * n;
    ll occupied_positions = rows.size() * n + cols.size() * n - rows.size() * cols.size();

    // Diagonal captures
    for (int d = -n; d <= n; ++d) {
        if (diags.count(d)) {
            int count = min(rows.size(), cols.size());
            occupied_positions += count;
        }
    }

    // Anti-diagonal captures
    for (int d = -n; d <= n; ++d) {
        if (anti_diags.count(d)) {
            int count = min(rows.size(), cols.size());
            occupied_positions += count;
        }
    }

    ll safe_positions = total_positions - occupied_positions;
    cout << safe_positions << endl;

    return 0;
}