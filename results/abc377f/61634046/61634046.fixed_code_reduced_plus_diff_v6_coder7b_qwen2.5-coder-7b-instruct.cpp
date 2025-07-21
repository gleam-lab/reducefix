#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_set<int> rows, cols, diag1, diag2;
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!rows.count(i) && !cols.count(j) && !diag1.count(i + j) && !diag2.count(i - j)) {
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}