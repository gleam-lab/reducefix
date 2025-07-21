#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    set<pair<long long, long long>> dangerous;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Generate all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {a+2, b+1}, {a+1, b+2}, {a-1, b+2}, {a-2, b+1},
            {a-2, b-1}, {a-1, b-2}, {a+1, b-2}, {a+2, b-1}
        };

        for (const auto& move : moves) {
            if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N) {
                dangerous.insert(move);
            }
        }
    }

    // The total safe positions are:
    // All positions (N*N) minus occupied positions (M) minus dangerous positions that aren't occupied
    long long total = N * N;
    long long unsafe = M;

    for (const auto& pos : dangerous) {
        if (pieces.find(pos) == pieces.end()) {
            unsafe++;
        }
    }

    cout << total - unsafe << '\n';

    return 0;
}