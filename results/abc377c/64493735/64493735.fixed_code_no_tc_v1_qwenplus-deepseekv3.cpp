#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> forbidden;
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // Generate all 8 possible attack positions
        vector<pair<int64_t, int64_t>> moves = {
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
            int64_t x = move.first;
            int64_t y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    int64_t total_squares = N * N;
    int64_t forbidden_count = forbidden.size();
    int64_t safe_squares = total_squares - forbidden_count;

    cout << safe_squares << '\n';

    return 0;
}