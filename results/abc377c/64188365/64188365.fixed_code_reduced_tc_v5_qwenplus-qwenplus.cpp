#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Direction vectors for all 8 possible knight moves in chess (relative positions)
const vector<pair<ll, ll>> directions = {
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
        occupied.insert({a, b});
    }

    set<pair<ll, ll>> forbidden;

    for (const auto& [x, y] : occupied) {
        forbidden.insert({x, y});  // The piece itself is not available
        for (const auto& [dx, dy] : directions) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                forbidden.insert({nx, ny});
            }
        }
    }

    // Total squares = n*n
    // Subtract number of forbidden squares
    cout << n * n - (ll)forbidden.size() << endl;

    return 0;
}