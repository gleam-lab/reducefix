#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    // Directions for capturing pieces
    vector<vector<ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    unordered_set<ll> occupied;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        occupied.insert(a * N + b);
    }

    ll total_squares = N * N;
    ll valid_squares = total_squares - occupied.size();

    for (auto& pos : occupied) {
        ll x = pos / N, y = pos % N;
        for (auto& dir : directions) {
            ll nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                valid_squares -= (occupied.count(nx * N + ny) == 0);
            }
        }
    }

    cout << valid_squares << endl;

    return 0;
}