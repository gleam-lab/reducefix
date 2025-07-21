#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    set<pair<ll, ll>> occupied;
    vector<pair<ll, ll>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;
        occupied.insert({a, b});

        // Mark all positions that this piece can attack
        for (auto [dx, dy] : deltas) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                occupied.insert({nx, ny});
            }
        }
    }

    // The total number of squares is n * n
    // We subtract the number of occupied or threatened squares
    cout << n * n - (ll)occupied.size() << endl;

    return 0;
}