#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pll> attacked;

    // 8 possible knight-like attack directions
    const vector<pair<ll, ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;

        // Add the piece itself to the attacked set (it's occupied and can't place a piece)
        attacked.insert({x, y});

        // Check each direction
        for (auto [dx, dy] : directions) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.insert({nx, ny});
            }
        }
    }

    // Total cells: N * N
    // Subtract number of attacked cells
    // But we need to be careful because some attacked positions might be out of bounds
    // and the original M pieces are also included in the 'attacked' set.
    
    // So we count all unique positions that are either:
    // - original pieces
    // - attacked positions
    ll total_attacked = attacked.size();

    // Calculate total empty and non-attacked cells
    __int128 total_cells = (__int128)N * (__int128)N;
    __int128 result = total_cells - (__int128)total_attacked;

    cout << result << endl;

    return 0;
}