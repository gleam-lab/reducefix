#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> under_attack;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All 8 possible knight moves
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                under_attack.insert({x, y});
            }
        }
    }

    // The total invalid squares are those either occupied or under attack
    set<pair<long long, long long>> invalid;
    invalid.insert(occupied.begin(), occupied.end());
    invalid.insert(under_attack.begin(), under_attack.end());

    long long total_squares = N * N;
    long long invalid_squares = invalid.size();
    long long valid_squares = total_squares - invalid_squares;

    cout << valid_squares << '\n';

    return 0;
}