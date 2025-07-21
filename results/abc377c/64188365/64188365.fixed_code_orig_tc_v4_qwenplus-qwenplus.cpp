#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> attacked;

    // Define the 8 possible attacking moves
    vector<pair<ll, ll>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b; // convert to 0-based index

        // Insert current piece into occupied set
        occupied.insert({a, b});

        // Compute all 8 attacked positions
        for (auto [dx, dy] : deltas) {
            ll x = a + dx;
            ll y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    // Remove positions that are already occupied from the attacked set
    for (auto pos : occupied) {
        attacked.erase(pos);
    }

    // Total unoccupied and unattacked positions
    ll total = N * N;
    ll invalid = occupied.size() + attacked.size();

    cout << total - invalid << "\n";

    return 0;
}