#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> under_attack;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        // Generate all 8 possible attack positions
        vector<pair<long long, long long>> directions = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& [x, y] : directions) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                under_attack.insert({x, y});
            }
        }
    }

    // Calculate safe positions: total positions - occupied - under_attack_positions_not_occupied
    long long total_safe = N * N - M;
    for (const auto& pos : under_attack) {
        if (existing_pieces.find(pos) == existing_pieces.end()) {
            total_safe--;
        }
    }

    cout << total_safe << '\n';

    return 0;
}