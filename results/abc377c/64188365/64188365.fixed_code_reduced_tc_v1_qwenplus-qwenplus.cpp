#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Direction vectors for all 8 possible L-shaped moves
const vector<pair<ll, ll>> dirs = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    ll n, m;
    cin >> n >> m;
    
    set<pair<ll, ll>> occupied;
    
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;
        occupied.emplace(a, b);
        
        // Check all 8 possible positions where this piece could threaten
        for (auto [dx, dy] : dirs) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                occupied.emplace(nx, ny);
            }
        }
    }
    
    // Total squares = n^2, subtract the number of squares that are either
    // occupied or threatened
    cout << (n * n) - (ll)occupied.size() << endl;
    
    return 0;
}