#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL n, m;
set<LL> row, col, diag1, diag2;

int main() {
    cin >> n >> m;
    while (m--) {
        LL x, y; cin >> x >> y;
        row.insert(x); col.insert(y); diag1.insert(x + y); diag2.insert(x - y);
    }
    
    LL res = n * n - row.size() - col.size() - diag1.size() - diag2.size();
    for (auto& x : row) res -= diag1.count(x + y);
    for (auto& y : col) res -= diag2.count(x - y);
    cout << res / 2 << endl; // Each intersection is counted twice
    return 0;
}