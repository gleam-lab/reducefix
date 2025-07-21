#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

// Custom hash to allow pairs in unordered_set
struct pair_hash {
    size_t operator()(const pair<long long, long long>& p) const {
        return ((size_t)p.first << 32) | p.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store all positions that are either occupied or threatened
    unordered_set<pair<long long, long long>, pair_hash> forbidden;

    // Offsets for the knight-like moves
    vector<pair<long long, long long>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Add current piece position
        forbidden.insert({a, b});

        // Add all threatened positions from this piece
        for (auto [dx, dy] : attack_offsets) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    // Total number of cells minus the number of forbidden cells
    cout << (N * NLL - (long long)forbidden.size()) << "\n";

    return 0;
}