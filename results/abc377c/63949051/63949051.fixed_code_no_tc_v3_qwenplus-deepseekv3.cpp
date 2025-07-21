#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    set<pair<long long, long long>> attacked;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // All possible attack positions
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            long long x = move.first, y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // Total safe positions: N^2 - (number of attacked positions + number of existing pieces)
    // Need to subtract positions that are both existing pieces and attacked positions
    long long total_attacked = attacked.size();
    long long total_pieces = pieces.size();
    
    // Count positions that are both existing and attacked
    long long overlap = 0;
    for (const auto &piece : pieces) {
        if (attacked.count(piece)) {
            overlap++;
        }
    }

    long long safe_positions = N * N - (total_attacked + total_pieces - overlap);
    cout << safe_positions << endl;

    return 0;
}