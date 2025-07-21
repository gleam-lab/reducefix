#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> attacked_positions;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        // All 8 possible attack positions
        vector<pair<long long, long long>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto& dir : directions) {
            long long new_a = a + dir.first;
            long long new_b = b + dir.second;
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                attacked_positions.insert({new_a, new_b});
            }
        }
    }

    // The total safe positions are N*N minus:
    // 1) positions already occupied
    // 2) positions that can be attacked
    // But we need to count each position only once, even if it's both occupied and attacked
    set<pair<long long, long long>> unsafe_positions;
    unsafe_positions.insert(existing_pieces.begin(), existing_pieces.end());
    unsafe_positions.insert(attacked_positions.begin(), attacked_positions.end());

    long long total_safe = N * N - unsafe_positions.size();
    cout << total_safe << endl;

    return 0;
}