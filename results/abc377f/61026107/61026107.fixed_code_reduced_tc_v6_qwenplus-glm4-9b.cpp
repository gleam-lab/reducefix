#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m; cin >> n >> m;
    set<pair<ll, ll>> row_col, diag1, diag2;
    for (ll i = 1; i <= m; i++) {
        ll a, b; cin >> a >> b;
        row_col.insert({a, b});
        diag1.insert({a - b, 2});  // Marking with 2 to distinguish from pairs
        diag2.insert({a + b, 2});  // Marking with 2 to distinguish from pairs
    }
    
    ll total = n * n;
    for (const auto& p : row_col) {
        total -= (n + abs(p.first) - 1) / abs(p.first);  // Sum of all elements in the set
    }
    for (const auto& p : diag1) {
        total -= (n + abs(p.first) - 2) / 2;  // Adjust for marking with 2
    }
    for (const auto& p : diag2) {
        total -= (n + abs(p.first) - 2) / 2;  // Adjust for marking with 2
    }
    
    cout << total << '\n';
    return 0;
}