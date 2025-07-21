#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Direction vectors for all 8 possible attack positions
const array<array<int, 2>, 8> directions = {{
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
}};

int main() {
    ll n, m;
    cin >> n >> m;
    
    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> threatened;
    
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;
        occupied.emplace(a, b);
        threatened.emplace(a, b);
    }
    
    // For each piece, mark the squares it can attack
    for (const auto& [x, y] : occupied) {
        for (const auto& [dx, dy] : directions) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                threatened.emplace(nx, ny);
            }
        }
    }
    
    // Total squares = n*n
    // Subtract number of threatened squares
    cout << n * n - (ll)threatened.size() << endl;
}