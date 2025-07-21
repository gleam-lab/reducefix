#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

using ll = long long;
using PII = pair<ll, ll>;

// Custom hash function for pair<ll, ll>
struct PairHash {
    size_t operator()(const PII& p) const {
        // Use a simple combination of hashes with a large prime shift
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 31);
    }
};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<PII, PairHash> attacked_cells;
    vector<PII> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based index
        a--; b--;

        // Insert the position itself as occupied (must not be placed)
        attacked_cells.insert({a, b});

        // For each attack offset, calculate and insert attacked positions
        for (auto [dx, dy] : attack_offsets) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                attacked_cells.insert({nx, ny});
            }
        }
    }

    // Total number of cells = N * N
    // Subtract number of attacked or occupied cells
    ll total_cells = N * N;
    ll result = total_cells - (ll)attacked_cells.size();

    cout << result << endl;

    return 0;
}