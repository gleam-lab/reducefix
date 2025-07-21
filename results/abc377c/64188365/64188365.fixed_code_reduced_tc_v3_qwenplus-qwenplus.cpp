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
    
    set<pair<ll,ll>> occupied;
    set<pair<ll,ll>> threatened;

    // Read all existing pieces
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;
        occupied.emplace(a, b);
    }

    // For each existing piece, mark the squares it can attack
    for (auto [x, y] : occupied) {
        for (auto [dx, dy] : dirs) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                threatened.emplace(nx, ny);
            }
        }
    }

    // Total squares that are either occupied or threatened
    ll bad_squares = occupied.size() + threatened.size();

    // The answer is total grid size minus bad squares
    cout << (n * n - bad_squares) << endl;

    return 0;
}