#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> captured;
    set<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        captured.insert({a, b});

        // Check all 8 possible knight moves
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                captured.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe = captured.size();
    long long safe = total - unsafe;

    cout << safe << '\n';

    return 0;
}