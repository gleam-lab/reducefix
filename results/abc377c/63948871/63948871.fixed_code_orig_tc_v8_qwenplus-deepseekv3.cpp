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

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> threatened;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Generate all 8 possible knight moves
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
                if (occupied.find({x, y}) == occupied.end()) {
                    threatened.insert({x, y});
                }
            }
        }
    }

    long long total_squares = N * N;
    long long occupied_count = occupied.size();
    long long threatened_count = threatened.size();

    // Squares that are either occupied or threatened
    long long unsafe = occupied_count + threatened_count;
    long long safe = total_squares - unsafe;

    cout << safe << endl;

    return 0;
}