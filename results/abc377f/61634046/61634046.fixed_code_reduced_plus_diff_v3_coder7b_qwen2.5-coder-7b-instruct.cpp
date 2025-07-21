#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9 + 10;
const int MAX_M = 1e3 + 10;

int n, m;
set<int> rows, cols, diags1, diags2;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x + y);
        diags2.insert(x - y);
    }
    
    long long total_squares = 1LL * n * n;
    long long captured_squares = 0;
    
    captured_squares += rows.size();
    captured_squares += cols.size();
    captured_squares += diags1.size();
    captured_squares += diags2.size();
    
    // Each intersection point is counted twice, so subtract them once
    for (auto x : rows) {
        for (auto y : cols) {
            if (diags1.count(x + y) && diags2.count(x - y)) {
                captured_squares--;
            }
        }
    }
    
    cout << total_squares - captured_squares << endl;
    return 0;
}