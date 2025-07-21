#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> dangerous;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Generate all 8 possible dangerous positions for each piece
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (auto &pos : moves) {
            long long x = pos.first;
            long long y = pos.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (occupied.find({x, y}) == occupied.end()) {
                    dangerous.insert({x, y});
                }
            }
        }
    }

    long long total_safe = N * N - occupied.size() - dangerous.size();
    cout << total_safe << endl;

    return 0;
}