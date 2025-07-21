#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Direction vectors for all 8 possible knight-like moves described in the problem
const array<array<int, 2>, 8> directions = {{
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
}};

int main() {
    ll n, m;
    cin >> n >> m;

    set<pair<ll, ll>> attacked_or_occupied;
    set<pair<ll, ll>> occupied;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b; // Convert to 0-based index
        occupied.emplace(a, b);
        attacked_or_occupied.emplace(a, b);

        // Mark all reachable attack positions from this piece
        for (const auto& [dx, dy] : directions) {
            ll na = a + dx;
            ll nb = b + dy;
            if (na >= 0 && na < n && nb >= 0 && nb < n) {
                attacked_or_occupied.emplace(na, nb);
            }
        }
    }

    // Total number of cells = n * n
    // Remove all occupied and attacked cells
    ll result = n * n - (ll)attacked_or_occupied.size();
    cout << result << endl;

    return 0;
}