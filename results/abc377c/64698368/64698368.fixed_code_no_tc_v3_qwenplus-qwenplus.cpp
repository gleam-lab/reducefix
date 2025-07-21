#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(a) (a).begin(),(a).end()

int main() {
    ll N, M;
    cin >> N >> M;

    // Use a set to store all positions that are unsafe (either has a piece or can be captured)
    unordered_set<ll> unsafe;

    vector<pair<ll, ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Normalize to 0-based index
        a--; b--;
        // Add the position itself as unsafe (since it's occupied)
        unsafe.insert(a * N + b);
        // For each direction, mark the capture-able position
        for (auto [dx, dy] : directions) {
            ll na = a + dx;
            ll nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                unsafe.insert(na * N + nb);
            }
        }
    }

    // Total number of cells is N*N
    // Subtract the number of unsafe cells
    cout << (N * N - static_cast<ll>(unsafe.size())) << endl;

    return 0;
}