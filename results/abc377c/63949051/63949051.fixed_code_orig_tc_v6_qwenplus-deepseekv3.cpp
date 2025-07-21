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

    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> dangerous_positions;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        // All 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                dangerous_positions.insert({x, y});
            }
        }
    }

    // The total safe positions are N^2 minus existing pieces minus dangerous positions not already existing
    long long total_safe = N * N;

    // Subtract the existing pieces
    total_safe -= existing_pieces.size();

    // Subtract dangerous positions that are not existing pieces
    for (const auto& pos : dangerous_positions) {
        if (existing_pieces.find(pos) == existing_pieces.end()) {
            total_safe--;
        }
    }

    cout << total_safe << endl;

    return 0;
}