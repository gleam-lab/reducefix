#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Direction vectors for all 8 possible L-shaped moves
const array<array<int,2>,8> dirs = {{
    {2,1}, {1,2}, {-1,2}, {-2,1},
    {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
}};

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
    }
    
    // Count of squares that are either occupied or can be attacked
    set<pair<ll, ll>> attacked_or_occupied = occupied;
    
    for (const auto& p : occupied) {
        ll x = p.first;
        ll y = p.second;
        
        for (const auto& d : dirs) {
            ll nx = x + d[0];
            ll ny = y + d[1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                attacked_or_occupied.emplace(nx, ny);
            }
        }
    }
    
    // Total number of cells is n*n, subtract the number of attacked or occupied cells
    cout << (n * n) - (ll)attacked_or_occupied.size() << endl;
    
    return 0;
}