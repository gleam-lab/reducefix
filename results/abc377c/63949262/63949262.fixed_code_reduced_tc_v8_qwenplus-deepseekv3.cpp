#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

using i128 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 N, M;
    cin >> N >> M;

    set<pair<i128, i128>> occupied;
    set<pair<i128, i128>> attackable;

    for (i128 k = 0; k < M; ++k) {
        i128 a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Generate all 8 possible attackable squares
        vector<pair<i128, i128>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            i128 i = move.first;
            i128 j = move.second;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                attackable.insert(move);
            }
        }
    }

    // Calculate total safe squares: N^2 - (occupied.size() + attackable.size() - intersection)
    // intersection is the squares that are both occupied and attackable
    i128 intersection = 0;
    for (const auto &square : occupied) {
        if (attackable.find(square) != attackable.end()) {
            intersection++;
        }
    }

    i128 total_safe = N * N - (occupied.size() + attackable.size() - intersection);
    cout << total_safe << "\n";

    return 0;
}