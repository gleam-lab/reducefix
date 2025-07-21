#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

// Hash function for unordered_set of pairs
struct pair_hash {
    size_t operator()(const P& p) const {
        // Use simple hash combination with XOR and shift
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<P, pair_hash> attacked_cells;
    
    // All 8 directions a knight can attack/capture from
    vector<P> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;

        // Add the cell itself (it's occupied and cannot be used)
        attacked_cells.insert({a, b});

        // Add all cells that this piece can attack
        for (auto [dx, dy] : attack_offsets) {
            ll x = a + dx;
            ll y = b + dy;
            if (0 <= x && x < N && 0 <= y && y < N) {
                attacked_cells.insert({x, y});
            }
        }
    }

    // Total number of cells: N*N
    // Subtract:
    // 1. Number of attacked cells
    // 2. Already occupied cells (already included in attacked_cells)
    cout << N * N - (ll)attacked_cells.size() << endl;

    return 0;
}