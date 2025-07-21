#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL n, m;
set<LL> rows, cols, ups, downs;

void add(LL x, LL y) {
    rows.insert(x);
    cols.insert(y);
    ups.insert(x - y);
    downs.insert(x + y);
}

bool exists(const set<LL>& s, LL val) {
    return s.find(val) != s.end();
}

LL solve() {
    LL total = n * n;
    
    // Subtract positions where pieces can be captured horizontally and vertically
    for (auto& x : rows) {
        total -= m - 1;
    }
    for (auto& y : cols) {
        total -= m - 1;
    }
    
    // Subtract positions where pieces can be captured diagonally
    for (auto& u : ups) {
        total -= m - abs(u);
    }
    for (auto& d : downs) {
        total -= m - abs(n + 1 - d);
    }
    
    // Add back positions counted twice (where pieces can be captured both horizontally and vertically)
    for (auto& x : rows) {
        for (auto& y : cols) {
            total++;
        }
    }
    
    // Add back positions counted twice (where pieces can be captured both diagonally)
    for (auto& u : ups) {
        for (auto& d : downs) {
            if (u == d) {
                total--;
            }
        }
    }
    
    return total;
}

int main() {
    cin >> n >> m;
    for (LL i = 0; i < m; ++i) {
        LL x, y;
        cin >> x >> y;
        add(x, y);
    }
    
    cout << solve() << endl;
    return 0;
}