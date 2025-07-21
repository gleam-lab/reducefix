#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});

        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long attacked_count = attacked.size();
    long long pieces_count = pieces.size();

    // Squares under attack or occupied
    set<pair<long long, long long>> under_attack_or_occupied = attacked;
    under_attack_or_occupied.insert(pieces.begin(), pieces.end());
    long long unavailable = under_attack_or_occupied.size();

    long long safe_squares = total_squares - unavailable;
    cout << safe_squares << endl;

    return 0;
}