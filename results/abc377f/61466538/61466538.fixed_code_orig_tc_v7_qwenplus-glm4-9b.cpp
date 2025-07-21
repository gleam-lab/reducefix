#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<pair<ll, ll>> pieces;
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }
    
    vector<ll> rows(n + 1, 0), cols(n + 1, 0), diag1(2 * n + 1, 0), diag2(2 * n + 1, 0);
    
    for (auto &p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        diag1[p.first + p.second]++;
        diag2[p.first - p.second]++;
    }
    
    ll captured = 0;
    
    // Count captured squares in rows and columns
    for (ll i = 1; i <= n; i++) {
        captured += rows[i] * n;
        captured += cols[i] * n;
    }
    
    // Count captured squares in diagonals
    for (ll i = 1; i <= 2 * n; i++) {
        if (diag1[i] > 1) captured++;
        if (diag2[i] > 1) captured++;
    }
    
    // Subtract double counted squares at the boundaries
    captured -= (n + 1) * 2;
    
    // Calculate empty squares
    ll empty_squares = n * n - captured;
    
    cout << empty_squares << endl;
    
    return 0;
}