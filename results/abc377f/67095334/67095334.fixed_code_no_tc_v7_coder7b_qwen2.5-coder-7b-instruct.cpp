#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define inf 1e9 + 7

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    set<int> rows, cols, diag1, diag2;
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }
    
    int ans = (n - (int)rows.size()) * (n - (int)cols.size());
    
    for (auto d : diag1) {
        set<int> s;
        for (auto x : rows) {
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }
        for (auto y : cols) {
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }
        int len = min(d, n - d + 1);
        ans -= len - s.size();
    }
    
    for (auto d : diag2) {
        set<int> s;
        for (auto x : rows) {
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }
        for (auto y : cols) {
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }
        int len = min(n - abs(d), n + abs(d));
        ans -= len - s.size();
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}