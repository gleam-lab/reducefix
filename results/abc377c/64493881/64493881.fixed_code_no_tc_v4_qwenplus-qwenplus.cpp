#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    // We'll use a hash to map (x, y) to a unique number: x * large_prime + y
    const int64_t LARGE_PRIME = 1000000007;

    auto point_hash = [&](int64_t x, int64_t y) {
        return x * LARGE_PRIME + y;
    };

    // Directions where a piece can attack
    vector<pair<int64_t, int64_t>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark the piece itself
        attacked_or_occupied.insert(point_hash(a, b));

        // Mark all potentially attacked squares
        for (auto [dx, dy] : attack_offsets) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_or_occupied.insert(point_hash(na, nb));
            }
        }
    }

    // Total cells - occupied or attacked cells
    int64_t total_cells = N * N;
    int64_t safe_cells = total_cells - static_cast<int64_t>(attacked_or_occupied.size());

    cout << safe_cells << '\n';

    return 0;
}