#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    set<pair<long long, long long>> attack_positions;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Generate all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N) {
                attack_positions.insert(move);
            }
        }
    }

    // Remove positions that are already occupied by pieces
    for (const auto &piece : pieces) {
        attack_positions.erase(piece);
    }

    long long total_safe = N * N - pieces.size() - attack_positions.size();
    cout << total_safe << endl;

    return 0;
}