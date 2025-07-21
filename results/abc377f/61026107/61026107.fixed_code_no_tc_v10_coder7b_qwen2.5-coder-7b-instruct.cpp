#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef HOME
#include<debug.h>
#else
#define dump(...)
#endif

struct Point {
    ll x, y;
    bool operator < (const Point& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    };
};

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    
    // Collect all occupied positions
    for (int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Calculate the number of invalid positions
    ll invalid_positions = 0;
    invalid_positions += rows.size() * n; // Positions in occupied rows
    invalid_positions += cols.size() * n; // Positions in occupied columns
    invalid_positions += diag1.size() * (n - abs(*diag1.rbegin())); // Positions in occupied diagonals (top-left to bottom-right)
    invalid_positions += diag2.size() * (n - abs(*diag2.rbegin())); // Positions in occupied diagonals (top-right to bottom-left)

    // Each diagonal intersection is counted twice, so we need to subtract those overlaps
    for (auto &r : rows) {
        for (auto &c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                invalid_positions--;
            } else if (diag1.count(r + c) || diag2.count(r - c)) {
                invalid_positions--;
            }
        }
    }

    // Output the number of valid positions
    cout << (n * n - invalid_positions) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}