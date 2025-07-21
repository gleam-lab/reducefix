#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<ll> attacked; // Use a single 64-bit key to represent position (a * N + b)
    const vector<pair<ll, ll>> dir = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;

        // Convert to 0-based index
        a--; b--;

        // Add the cell itself since we cannot place on non-empty cells
        ll key = a * N + b;
        attacked.insert(key);

        // Generate all knight-like attack positions and mark them as attacked
        for (auto [dx, dy] : dir) {
            ll na = a + dx;
            ll nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                ll key = na * N + nb;
                attacked.insert(key);
            }
        }
    }

    // Total number of cells = N * N
    // Subtract:
    // 1. Number of attacked cells
    // 2. Number of already occupied cells (M)
    ll totalCells = N * N;
    ll result = totalCells - (ll)attacked.size();

    cout << result << endl;

    return 0;
}