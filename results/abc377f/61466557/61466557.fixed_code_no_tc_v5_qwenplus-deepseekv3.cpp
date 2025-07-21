#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pll> queens(m);
    for (auto &q : queens) {
        cin >> q.first >> q.second;
    }
    
    unordered_set<ll> rows, cols, diag1, diag2;
    for (const auto &q : queens) {
        rows.insert(q.first);
        cols.insert(q.second);
        diag1.insert(q.first - q.second);
        diag2.insert(q.first + q.second);
    }
    
    ll total = n * n;
    
    // Subtract squares attacked by rows or columns
    total -= rows.size() * n;
    total -= cols.size() * n;
    total += rows.size() * cols.size();
    
    // Subtract squares attacked by diagonals (i - j = d)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        total -= cnt;
    }
    
    // Subtract squares attacked by anti-diagonals (i + j = d)
    for (ll d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        total -= cnt;
    }
    
    // Add back squares that were subtracted twice (intersection of rows/cols with diagonals/anti-diagonals)
    for (const auto &q : queens) {
        ll r = q.first, c = q.second;
        if (rows.count(r) && cols.count(c)) {
            total++;
        }
        if (diag1.count(r - c)) {
            total++;
        }
        if (diag2.count(r + c)) {
            total++;
        }
    }
    
    // Subtract the squares already occupied by queens
    total -= m;
    
    cout << total << "\n";
    
    return 0;
}